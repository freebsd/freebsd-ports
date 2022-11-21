PORTNAME=	cospend
PORTVERSION=	1.5.4
CATEGORIES=	finance www editors
MASTER_SITES=	https://github.com/eneiluj/${PORTNAME}-nc/releases/download/v${PORTVERSION}/
PKGNAMEPREFIX=	nextcloud-
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DIST_SUBDIR=	nextcloud

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Cospend app for Nextcloud
WWW=		https://apps.nextcloud.com/apps/cospend

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	nextcloud${PHP_PKGNAMESUFFIX}>=25:www/nextcloud@${PHP_FLAVOR}

USES=		php:flavors
IGNORE_WITH_PHP=	82
NO_BUILD=	yes
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
WWWDIR=		${PREFIX}/www/nextcloud/apps-pkg/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})
	@(cd ${WRKSRC}; ${FIND} . -not -type d) | ${SORT} | \
		${SED} -e 's,^\.,${WWWDIR_REL},' >> ${TMPPLIST}

.include <bsd.port.mk>
