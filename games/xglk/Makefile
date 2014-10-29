# Created by: Peter Pentchev <roam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xglk
PORTVERSION=	411
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.ifarchive.org/if-archive/programming/glk/implementations/
DISTNAME=	${PORTNAME}-0${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X Windows Implementation of the Glk API

LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XORG=	x11
MAKE_ENV+=	AR=${AR} RANLIB=${RANLIB} ECHO=${ECHO} RM=${RM:Q}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/xglk
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/xglk/
	${INSTALL_DATA} ${WRKSRC}/libxglk.a ${STAGEDIR}${PREFIX}/lib/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Make.xglk ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
