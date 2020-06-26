# $FreeBSD$

PORTNAME=	xxhash
PORTVERSION=	0.7.4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extremely fast non-cryptographic hash algorithm

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake

USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	Cyan4973
GH_PROJECT=	xxHash

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/xxhsum
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libxxhash.so.${PORTVERSION}

.include <bsd.port.mk>
