# Support for Nextcloud apps
#
# Feature:	nextcloud
# Usage:	USES=nextcloud
#
# MAINTAINER: brnrd@FreeBSD.org

.if !defined(_INCLUDE_USES_NEXTCLOUD_MK)
_INCLUDE_USES_NEXTCLOUD_MK=	yes

NEXTCLOUD_BASE?=	www/nextcloud

NEXTCLOUD_DIR=		${PREFIX}/${NEXTCLOUD_BASE}
NEXTCLOUD_APPSDIR?=	${PREFIX}/${NEXTCLOUD_BASE}/apps-pkg

PKGNAMEPREFIX=	nextcloud-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
WRKSRC?=	${WRKDIR}/${PORTNAME}

.  if ${DISTNAME} == ${PORTNAME}
DIST_SUBDIR?=   nextcloud/${PORTNAME}-${PORTVERSION}
.  else
DIST_SUBDIR?=	nextcloud
.  endif

MASTER_SITES?=   https://github.com/nextcloud-releases/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/

LICENSE?=	AGPLv3

RUN_DEPENDS=	nextcloud${PHP_PKGNAMESUFFIX}>=${NEXTCLOUD_RUN_DEPENDS}:www/nextcloud@${PHP_FLAVOR}

USES+=		php:flavors
NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR?=		${NEXTCLOUD_APPSDIR}/${PORTNAME}

NEXTCLOUD_APP_PKGMESSAGE=	${WRKDIR}/pkg-message
_PKGMESSAGES+=	${NEXTCLOUD_APP_PKGMESSAGE}

_USES_stage=   899:add-pkg-message
add-pkg-message:
	@${ECHO_CMD} "[" > ${NEXTCLOUD_APP_PKGMESSAGE}
	@${ECHO_CMD} "{ type: install" >> ${NEXTCLOUD_APP_PKGMESSAGE}
	@${ECHO_CMD} "  message: <<EOD" >> ${NEXTCLOUD_APP_PKGMESSAGE}
	@${ECHO_CMD} "Run \`occ upgrade\` to create the Nextcloud ${PORTNAME} app database structure" >> ${NEXTCLOUD_APP_PKGMESSAGE}
	@${ECHO_CMD} "EOD" >> ${NEXTCLOUD_APP_PKGMESSAGE}
	@${ECHO_CMD} "}," >> ${NEXTCLOUD_APP_PKGMESSAGE}
	@${ECHO_CMD} "{ type: upgrade:" >> ${NEXTCLOUD_APP_PKGMESSAGE}
	@${ECHO_CMD} "  message: <<EOD" >> ${NEXTCLOUD_APP_PKGMESSAGE}
	@${ECHO_CMD} "Run \`occ upgrade\` to update the Nextcloud ${PORTNAME} app database structure" >> ${NEXTCLOUD_APP_PKGMESSAGE}
	@${ECHO_CMD} "EOD" >> ${NEXTCLOUD_APP_PKGMESSAGE}
	@${ECHO_CMD} "}" >> ${NEXTCLOUD_APP_PKGMESSAGE}
	@${ECHO_CMD} "]" >> ${NEXTCLOUD_APP_PKGMESSAGE}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	@(cd ${WRKSRC}; ${FIND} . -not -type d) | ${SORT} | \
			${SED} -e 's,^\.,${WWWDIR_REL},' >> ${TMPPLIST}

.endif
