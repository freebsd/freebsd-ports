PORTNAME=	gnats
PORTVERSION=	4.1.0
PORTREVISION=	24
CATEGORIES=	databases devel
MASTER_SITES=	GNU
PKGNAMESUFFIX=	4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNATS, the GNU Problem Report Management System
WWW=		https://www.gnu.org/software/gnats/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_mips=		Does not build: error: conflicting types for yy_scan_string
BROKEN_mips64=		Does not build: error: conflicting types for yy_scan_string

USES=		cpe gettext-runtime gmake
CPE_VENDOR=	gnu
USE_GCC=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS+=	--sharedstatedir=${GNATSDBDIR}

.ifdef WANT_FREEFALL_CFG
EXTRA_PATCHES+=		${PATCHDIR}/extrapatch-*
GNATSDBDIR=		${DATADIR}
CONFIGURE_ARGS+=	--with-gnats-default-db=${GNATSDBDIR}/gnats-db
WITH_SUBMITTER_ID=	current-users
WITH_ORGANIZATION=	FreeBSD
WITH_GNATSD_SERVICE=	support
.endif

.ifdef WITH_SUBMITTER_ID
CONFIGURE_ARGS+=	--with-submitter=${WITH_SUBMITTER_ID}
.endif

.ifdef WITH_ORGANIZATION
CONFIGURE_ARGS+=	--with-organization=${WITH_ORGANIZATION:Q}
.endif

.ifdef WITH_GNATSD_SERVICE
CONFIGURE_ARGS+=	--with-gnats-service=${WITH_GNATSD_SERVICE}
.endif

USERS=		gnats

PKGINSTALL=	${WRKDIR}/pkg-install
PKGMESSAGE=	${WRKDIR}/pkg-message
INFO=		gnats-faq gnats
PLIST_SUB=	GNATSDBDIR=${GNATSDBDIR}
PORTDOCS=	NEWS UPGRADING

OPTIONS_DEFINE=	DOCS EMACS SERVER
OPTIONS_DEFAULT=SERVER
OPTIONS_SUB=	yes

EMACS_DESC=	Install Emacs Lisp support file
SERVER_DESC=	Install the gnats server too

EMACS_USES=	emacs
EMACS_CONFIGURE_ON=--with-lispdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}
EMACS_PLIST_SUB_OFF=	EMACS_SITE_LISPDIR="@comment "
EMACS_VARS=	EMACS_NO_DEPENDS=yes
SERVER_ALL_TARGET_OFF=	all-tools
SERVER_INSTALL_TARGET_OFF=	install-tools

GNATSDBDIR?=		/var/db/gnats

.include <bsd.port.options.mk>

pre-everything::
.if !defined(PACKAGE_BUILDING) && !defined(WANT_FREEFALL_CFG)
	@${ECHO} "============================================================="
	@${ECHO}
	@${ECHO} "You can build ${PKGNAME} with the following options:"
	@${ECHO}
	@${ECHO} "WITH_SUBMITTER_ID=unknown        default submitter-id"
	@${ECHO} "WITH_ORGANIZATION='unknown'      default organization"
	@${ECHO} "WITH_GNATSD_SERVICE=support      default gnatsd port name"
	@${ECHO}
	@${ECHO} "============================================================="
	@${ECHO}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|info man|man|g' ${WRKSRC}/doc/Makefile.in

pre-configure:
	@${ECHO_CMD} 'RELEASE_TAG="\`uname -srm\`"' > ${WRKSRC}/release-info

post-build:
	@for doc in pkg-message pkg-install; do \
		${SED} -e 's,%%PREFIX%%,${STAGEDIR}${PREFIX},g' \
			-e 's,%%GNATSDBDIR%%,${GNATSDBDIR},g' \
			${PKGDIR}/$${doc} >${WRKDIR}/$${doc}; \
	done

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gnats

post-install-SERVER-on:
	${MV} ${STAGEDIR}${ETCDIR}/databases.default \
		${STAGEDIR}${ETCDIR}/databases.sample
	${MV} ${STAGEDIR}${ETCDIR}/gnatsd.host_access.default \
		${STAGEDIR}${ETCDIR}/gnatsd.host_access.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
