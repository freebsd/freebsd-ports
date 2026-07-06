PORTNAME=	pie
DISTVERSION=	1.4.7
CATEGORIES=	devel
MASTER_SITES=	https://github.com/php/${PORTNAME}/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.phar
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	PHP Installer for Extensions
WWW=		https://github.com/php/pie

LICENSE=	MIT

USES=		php:flavors
USE_PHP=	fliter iconv phar

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${PORTNAME}

do-extract:
	${MKDIR} ${WRKSRC}/
	${CP} ${_DISTDIR}/${PORTNAME}${EXTRACT_SUFX} ${WRKSRC}/

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}${EXTRACT_SUFX} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
