PORTNAME=	arqiver
DISTVERSION=	1.0.1
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/tsujan/${PORTNAME}/releases/download/V${DISTVERSION}/
DISTNAME=	Arqiver-${DISTVERSION}

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Simple Qt archive manager
WWW=		https://github.com/tsujan/Arqiver

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	7z:archivers/7-zip

USES=		desktop-file-utils gl qmake qt:6 tar:xz
USE_GL=		opengl
USE_QT=		base svg tools:build

.include <bsd.port.mk>
