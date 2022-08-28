PORTNAME=	streamvbyte
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1
CATEGORIES=	archivers

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Integer compression with SIMD based on Google's varint

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc=		Test fails on big-endian systems
BROKEN_powerpc64=	Test fails on big-endian systems

USES=		cmake
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	lemire

CFLAGS+=	-fPIC	# For vbz-compression using static lib

do-test:
	cd ${WRKDIR}/.build && ./unit

.include <bsd.port.mk>
