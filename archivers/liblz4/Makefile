# Created by: adamw
# $FreeBSD$

PORTNAME=	lz4
PORTVERSION=	131
DISTVERSIONPREFIX=	r
CATEGORIES=	archivers
PKGNAMEPREFIX=	lib

MAINTAINER=	martin@waschbuesch.de
COMMENT=	LZ4 compression library, lossless and very fast

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	Cyan4973

USES=		gmake pathfix pkgconfig
USE_LDCONFIG=	yes
PATHFIX_MAKEFILEIN=	Makefile

ALL_TARGET=	default		# don't remove this
SO_VER=		1.7.1
PLIST_SUB+=	SO_VER=${SO_VER} SO_VER_MAJ=${SO_VER:R:R}
LIBDIR=		${PREFIX}/lib

post-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} \
		-e '/^MANDIR :=/s|share/||' \
		-e 's/kFreeBSD/& FreeBSD/'
	@${REINPLACE_CMD} -e '/^all:/s/$$/ liblz4.pc/' \
		${WRKSRC}/lib/Makefile
	@${REINPLACE_CMD} -e '/^all:/s|fullbench.*||' \
		${WRKSRC}/programs/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/lz4*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liblz4.so.${SO_VER}

.include <bsd.port.mk>
