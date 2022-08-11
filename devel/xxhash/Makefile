PORTNAME=	xxhash
PORTVERSION=	0.8.1
PORTREVISION=	1
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

PORTSCOUT=	limit:^v[0-9\.]*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xxhsum
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxxhash.so

.include <bsd.port.mk>
