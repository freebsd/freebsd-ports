PORTNAME=	fractgen
DISTVERSION=	3.0.2
CATEGORIES=	graphics
MASTER_SITES=	https://www.nntb.no/~dreibh/fractalgenerator/download/

MAINTAINER=	thomas.dreibholz@gmail.com
COMMENT=	Fractal Generator
WWW=		https://www.nntb.no/~dreibh/fractalgenerator/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libGLX.so:graphics/libglvnd

USES=		cmake compiler:c++17-lang desktop-file-utils gl qt:6 \
		shared-mime-info tar:xz
USE_GL=		gl opengl
USE_QT=		base tools

.include <bsd.port.mk>
