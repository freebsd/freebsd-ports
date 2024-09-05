PORTNAME=	xxhash
PORTVERSION=	0.8.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extremely fast non-cryptographic hash algorithm
WWW=		https://xxhash.com/ \
		https://github.com/Cyan4973/xxHash

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake

MAKE_ARGS=	MANDIR=${PREFIX}/share/man/man1
TEST_TARGET=	check
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	Cyan4973
GH_PROJECT=	xxHash

PORTSCOUT=	limit:^v[0-9\.]*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xxhsum ${STAGEDIR}${PREFIX}/lib/libxxhash.so

.include <bsd.port.mk>
