PORTNAME=	hipercontracer
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	https://www.uni-due.de/~be0001/hipercontracer/download/

MAINTAINER=	dreibh@iem.uni-due.de
COMMENT=	High-Performance Connectivity Tracer (HiPerConTracer)
WWW=		https://www.uni-due.de/~be0001/hipercontracer/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_atomic.so:devel/boost-libs

USES=		cmake compiler:c++14-lang python shebangfix tar:xz
USE_LDCONFIG=	yes

SHEBANG_FILES=	src/addressinfogenerator src/get-default-ips src/tracedataimporter

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR:PATH=${PREFIX}/man
PLIST_SUB=	PORTVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e '/^#include <set>/ { x; s/^/#include <map>/; G; }' \
		${WRKSRC}/src/tools.h ${WRKSRC}/src/traceroute.h

.include <bsd.port.mk>
