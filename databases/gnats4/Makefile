# New ports collection makefile for:	gnats4
# Date created:				22 Aug 2003
# Whom:					Oliver Eikemeier <eikemeier@fillmore-labs.com>
#
# $FreeBSD$
#

PORTNAME=		gnats
PORTVERSION=		4.0
PORTREVISION=		2
CATEGORIES=		databases devel
MASTER_SITES=		http://home.pacific.net.au/~meganandaj/ \
			http://www.yngve.com/%SUBDIR%/ \
			# ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gnats

MAINTAINER=		eik@FreeBSD.org
COMMENT=		GNATS, the GNU Problem Report Management System

GNU_CONFIGURE=		yes
USE_GMAKE=		yes

LATEST_LINK=		${PKGNAMEPREFIX}gnats4${PKGNAMESUFFIX}
CONFLICTS=		gnats-3.*

PKGMESSAGE=		${WRKDIR}/pkg-message
PKGINSTALL=		${WRKDIR}/pkg-install

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

PLIST_SUB=		GNATSDBDIR=${GNATSDBDIR}

MAN1=			edit-pr.1 query-pr.1 send-pr.1
MAN5=			databases.5 dbconfig.5
MAN7=			gnats.7
MAN8=			delete-pr.8 file-pr.8 gen-index.8 gnatsd.8 \
			mkcat.8 mkdb.8 pr-edit.8 queue-pr.8 rmcat.8
INFO=			gnats-faq gnats
DOCFILES=		NEWS UPGRADING

.ifdef WITH_EMACS_PORT
EMACS_PORT_NAME=	${WITH_EMACS_PORT}
CONFIGURE_ARGS+=	--with-lispdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}
.else
PLIST_SUB+=		EMACS_SITE_LISPDIR="@comment "
.endif

.ifdef CLIENT_ONLY
ALL_TARGET=		all-tools
INSTALL_TARGET=		install-tools
PLIST_SUB+=		SERVER="@comment "
PKGNAMESUFFIX=		-client
CONFLICTS+=		${PKGNAMEPREFIX}${PORTNAME}-4.*
.else
PLIST_SUB+=		SERVER=""
CONFLICTS+=		${PKGNAMEPREFIX}${PORTNAME}-client-4.*
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
	@${ECHO} "WITH_EMACS_PORT=emacs            with Emacs support"
	@${ECHO}
	@${ECHO} "============================================================="
	@${ECHO}
.endif

pre-configure:
	@${ECHO_CMD} 'RELEASE_TAG="\`uname -srm\`"' > ${WRKSRC}/release-info

post-build:
	@for doc in pkg-message pkg-install; do \
		${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
			-e 's,%%GNATSDBDIR%%,${GNATSDBDIR},g' \
			${PKGDIR}/$${doc} >${WRKDIR}/$${doc} ; \
	done

pre-install:
	@${MKDIR} ${PREFIX}/libexec/gnats
	@${SETENV} "PKG_PREFIX=${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.ifndef CLIENT_ONLY
	@for conf in databases gnatsd.host_access; do \
		[ -f ${PREFIX}/etc/gnats/$${conf} ] \
		|| ${CP} ${PREFIX}/etc/gnats/$${conf}.default ${PREFIX}/etc/gnats/$${conf}; \
	done
.endif
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	@for doc in ${DOCFILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$${doc} ${DOCSDIR}; \
	done
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
