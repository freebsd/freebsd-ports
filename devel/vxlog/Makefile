PORTNAME=	vxlog
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://bitbucket.org/klepa/vxlog/downloads/ \
		SF/${PORTNAME}

MAINTAINER=	konstantin.lepa@gmail.com
COMMENT=	C++ logging library
WWW=		https://sourceforge.net/projects/vxlog/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/doc/COPYING.txt

USES=		cmake
USE_LDCONFIG=	yes

CMAKE_ARGS+=	-DTESTING:BOOL=OFF

.include <bsd.port.mk>
