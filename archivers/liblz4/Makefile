# Created by: adamw
# $FreeBSD$

PORTNAME=	lz4
PORTVERSION=	123
CATEGORIES=	archivers
PKGNAMEPREFIX=	lib

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	LZ4 compression library, lossless and very fast

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	Cyan4973
GH_PROJECT=	lz4
GH_TAGNAME=	r${PORTVERSION}
GH_COMMIT=	c0054ca

CONFLICTS=	lz4-*

USES=		gmake pkgconfig
USE_LDCONFIG=	yes

ALL_TARGET=	all liblz4 liblz4.pc
SO_VER=		1.3.1

post-patch:
	${REINPLACE_CMD} -e 's|kFreeBSD|& FreeBSD|' \
		${WRKSRC}/Makefile ${WRKSRC}/programs/Makefile
	${REINPLACE_CMD} -e '/^all:/s|fullbench.*||' \
		${WRKSRC}/programs/Makefile

do-install:
	${INSTALL_LIB} ${WRKSRC}/liblz4.so.${SO_VER} ${STAGEDIR}${PREFIX}/lib
	${LN} -sf liblz4.so.${SO_VER} ${STAGEDIR}${PREFIX}/lib/liblz4.so.${SO_VER:R:R}
	${LN} -sf liblz4.so.${SO_VER:R:R} ${STAGEDIR}${PREFIX}/lib/liblz4.so
	${INSTALL_LIB} ${WRKSRC}/liblz4.a ${STAGEDIR}${PREFIX}/lib

	${INSTALL_DATA} ${WRKSRC}/liblz4.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/lz4.h ${WRKSRC}/lz4hc.h ${STAGEDIR}${PREFIX}/include

	${INSTALL_PROGRAM} ${WRKSRC}/programs/lz4 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/programs/lz4c ${STAGEDIR}${PREFIX}/bin
	${LN} -sf lz4 ${STAGEDIR}${PREFIX}/bin/lz4cat
	${INSTALL_MAN} ${WRKSRC}/programs/lz4.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/programs/lz4c.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/programs/lz4cat.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
