PORTNAME=	xxhash
PORTVERSION=	0.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extremely fast non-cryptographic hash algorithm

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake

USE_LDCONFIG=	yes
TEST_TARGET=	check

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	Cyan4973
GH_PROJECT=	xxHash

PORTSCOUT=	skipv:r42

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xxhsum
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxxhash.so.${PORTVERSION}

.include <bsd.port.mk>
