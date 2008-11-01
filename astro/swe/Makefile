# New ports collection makefile for:	swe
# Date created:				30 Oct 2008
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	swe
PORTVERSION=	1.75.00
CATEGORIES=	astro devel
MASTER_SITES=	ftp://ftp.astro.com/pub/swisseph/
DISTNAME=	${PORTNAME}_unix_src_${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	The High Precision Ephemeris Developed By Astrodienst

WRKSRC=		${WRKDIR}/src
USE_GMAKE=	yes
ALL_TARGET=
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-pedantic||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/libswe.a ${LOCALBASE}/lib
	${MKDIR} ${LOCALBASE}/include/swe
	${INSTALL_DATA} ${WRKSRC}/*.h ${LOCALBASE}/include/swe

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/doc/* ${DOCSDIR}/
.endif

.include <bsd.port.mk>
