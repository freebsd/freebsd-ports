PORTNAME=	fractgen
DISTVERSION=	3.0.6
CATEGORIES=	graphics
MASTER_SITES=	https://www.nntb.no/~dreibh/fractalgenerator/download/

MAINTAINER=	thomas.dreibholz@gmail.com
COMMENT=	Fractal Generator
WWW=		https://www.nntb.no/~dreibh/fractalgenerator/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++17-lang desktop-file-utils gl qt:6 \
		shared-mime-info tar:xz
USE_GL=		opengl
USE_QT=		base tools:build

.include <bsd.port.mk>
