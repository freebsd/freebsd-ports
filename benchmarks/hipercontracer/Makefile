PORTNAME=	hipercontracer
PORTVERSION=	1.6.10
CATEGORIES=	benchmarks
MASTER_SITES=	https://www.nntb.no/~dreibh/hipercontracer/download/

MAINTAINER=	thomas.dreibholz@gmail.com
COMMENT=	High-Performance Connectivity Tracer (HiPerConTracer)
WWW=		https://www.nntb.no/~dreibh/hipercontracer/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_atomic.so:devel/boost-libs

USES=		cmake compiler:c++14-lang python shebangfix tar:xz
USE_LDCONFIG=	yes

SHEBANG_FILES=	src/addressinfogenerator src/get-default-ips src/tracedataimporter

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR:PATH=${PREFIX}/man
PLIST_SUB=	PORTVERSION=${PORTVERSION}

.include <bsd.port.mk>
