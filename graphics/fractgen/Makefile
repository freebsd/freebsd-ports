PORTNAME=	fractgen
DISTVERSION=	2.1.14
CATEGORIES=	graphics
MASTER_SITES=	https://www.nntb.no/~dreibh/fractalgenerator/download/

MAINTAINER=	thomas.dreibholz@gmail.com
COMMENT=	Fractal Generator
WWW=		https://www.nntb.no/~dreibh/fractalgenerator/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++14-lang desktop-file-utils shared-mime-info \
		tar:xz qt:5
USE_QT=		core xml widgets printsupport gui \
		buildtools:build qmake:build linguisttools:build

.include <bsd.port.mk>
