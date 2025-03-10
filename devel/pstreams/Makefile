PORTNAME=	pstreams
PORTVERSION=	1.0.4
CATEGORIES=	devel
MASTER_SITES=	SF/pstreams/pstreams/Release%20${PORTVERSION:R}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	C++ utility for simple IOStream-based IPC
WWW=		https://pstreams.sourceforge.net/ \
		https://github.com/jwakely/pstreams

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	include/pstreams/pstream.h

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/pstreams/
	${INSTALL_DATA} ${WRKSRC}/pstream.h ${STAGEDIR}${PREFIX}/include/pstreams/pstream.h

.include <bsd.port.mk>
