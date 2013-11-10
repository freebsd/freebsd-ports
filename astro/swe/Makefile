# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	swe
PORTVERSION=	1.80.00
CATEGORIES=	astro devel
MASTER_SITES=	ftp://ftp.astro.com/pub/swisseph/
DISTNAME=	${PORTNAME}_unix_src_${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	High Precision Ephemeris Developed By Astrodienst

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/src
USES=		gmake
ALL_TARGET=	#
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-pedantic||' \
		-e 's|CFLAGS =|CFLAGS ?=|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/libswe.a ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/include/swe
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/swe
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/doc/* ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
