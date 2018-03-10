# Created by: Oliver Eikemeier <eikemeier@fillmore-labs.com>
# $FreeBSD$

PORTNAME=	gnats
PORTVERSION=	4.1.0
PORTREVISION=	8
CATEGORIES=	databases devel
MASTER_SITES=	GNU
PKGNAMESUFFIX=	4

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	GNATS, the GNU Problem Report Management System

BROKEN_powerpc64=	Does not build: error: conflicting types for yy_scan_string

GNU_CONFIGURE=	yes
USES=		cpe gmake makeinfo
USE_GCC=	any
USERS=		gnats

CPE_VENDOR=	gnu

PKGMESSAGE=	${WRKDIR}/pkg-message
PKGINSTALL=	${WRKDIR}/pkg-install

.ifdef WANT_FREEFALL_CFG
EXTRA_PATCHES+=		${PATCHDIR}/extrapatch-*
GNATSDBDIR=		${DATADIR}
CONFIGURE_ARGS+=	--with-gnats-default-db=${GNATSDBDIR}/gnats-db
WITH_SUBMITTER_ID=	current-users
WITH_ORGANIZATION=	FreeBSD
WITH_GNATSD_SERVICE=	support
.endif

GNATSDBDIR?=		/var/db/gnats

CONFIGURE_ARGS+=	--sharedstatedir=${GNATSDBDIR}

.ifdef WITH_SUBMITTER_ID
CONFIGURE_ARGS+=	--with-submitter=${WITH_SUBMITTER_ID}
.endif

.ifdef WITH_ORGANIZATION
CONFIGURE_ARGS+=	--with-organization=${WITH_ORGANIZATION:Q}
.endif

.ifdef WITH_GNATSD_SERVICE
CONFIGURE_ARGS+=	--with-gnats-service=${WITH_GNATSD_SERVICE}
.endif

PLIST_SUB=	GNATSDBDIR=${GNATSDBDIR}
INFO=		gnats-faq gnats
PORTDOCS=	NEWS UPGRADING

OPTIONS_DEFINE=	DOCS EMACS SERVER
OPTIONS_DEFAULT=SERVER
OPTIONS_SUB=	yes
EMACS_USES=	emacs
EMACS_DESC=	Install Emacs Lisp support file
EMACS_VARS=	EMACS_NO_DEPENDS=yes
SERVER_DESC=	Install the gnats server too

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MSERVER}
ALL_TARGET=	all-tools
INSTALL_TARGET=	install-tools
.endif

.if ${PORT_OPTIONS:MEMACS}
CONFIGURE_ARGS+=--with-lispdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}
.else
PLIST_SUB+=	EMACS_SITE_LISPDIR="@comment "
.endif

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

post-install:
.if ${PORT_OPTIONS:MSERVER}
	${MV} ${STAGEDIR}${ETCDIR}/databases.default \
		${STAGEDIR}${ETCDIR}/databases.sample
	${MV} ${STAGEDIR}${ETCDIR}/gnatsd.host_access.default \
		${STAGEDIR}${ETCDIR}/gnatsd.host_access.sample
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
