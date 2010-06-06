# New ports collection makefile for:	edge
# Date created:				2007-11-30
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	edge
PORTVERSION=	1.29
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/EDGE%20Source%20Code/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}-linux${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DOOM style engine aimed at the Total Conversion developer

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		vorbis.4:${PORTSDIR}/audio/libvorbis

USE_SCONS=	yes
USE_SDL=	sdl
SCONS_ARGS=	release=true

post-patch:
	@${REINPLACE_CMD} -e 's|%%DMDIR%%|${DMDIR}|;' ${WRKSRC}/src/e_main.cc
	@${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|;' ${WRKSRC}/SConstruct

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gledge32 ${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/edge.wad ${DMDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/*.txt ${DOCSDIR}
.endif

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.mk>
