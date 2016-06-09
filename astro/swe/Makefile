# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	swe
PORTVERSION=	2.05.01
CATEGORIES=	astro devel
MASTER_SITES=	ftp://ftp.astro.com/pub/swisseph/
DISTNAME=	${PORTNAME}_unix_src_${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	High Precision Ephemeris Developed By Astrodienst

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/src
USES=		gmake
ALL_TARGET=	#
MAKE_ARGS=	CFLAGS="${CFLAGS}"
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_DATA} ${WRKSRC}/libswe.a ${STAGEDIR}${PREFIX}/lib
	${MKDIR} ${STAGEDIR}${PREFIX}/include/swe
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/swe

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/doc/* ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
