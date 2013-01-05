# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	swe
PORTVERSION=	1.78.00
CATEGORIES=	astro devel
MASTER_SITES=	ftp://ftp.astro.com/pub/swisseph/
DISTNAME=	${PORTNAME}_unix_src_${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	High Precision Ephemeris Developed By Astrodienst

WRKSRC=		${WRKDIR}/src
USE_GMAKE=	yes
ALL_TARGET=	#
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-pedantic||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/libswe.a ${LOCALBASE}/lib
	${MKDIR} ${LOCALBASE}/include/swe
	${INSTALL_DATA} ${WRKSRC}/*.h ${LOCALBASE}/include/swe

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/doc/* ${DOCSDIR}/
.endif

.include <bsd.port.mk>
