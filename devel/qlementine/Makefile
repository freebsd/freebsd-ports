PORTNAME=	qlementine
PORTVERSION=	1.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Modern QStyle for desktop Qt6 applications
WWW=		https://oclero.github.io/qlementine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake gl qt:6

USE_QT=		base svg tools:build
USE_GL=		opengl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	oclero

.include <bsd.port.mk>
