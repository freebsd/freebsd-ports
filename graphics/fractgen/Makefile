PORTNAME=	fractgen
PORTVERSION=	2.1.11
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://www.uni-due.de/~be0001/fractalgenerator/download/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	Fractal Generator
WWW=		https://www.uni-due.de/~be0001/fractalgenerator/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++11-lang tar:xz cmake qt:5
USE_QT=		core xml widgets printsupport gui \
		buildtools:build qmake:build linguisttools:build

.include <bsd.port.mk>
