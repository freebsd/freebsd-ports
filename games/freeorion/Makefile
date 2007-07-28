# New ports collection makefile for:	freeorion
# Date created:				2007-04-29
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	freeorion
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.alepulver.com.ar/distfiles/

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Open-source, platform independent galactic conquest game

LIB_DEPENDS=	GiGi.0:${PORTSDIR}/x11-toolkits/gigi \
		alut.1:${PORTSDIR}/audio/freealut \
		graph.3:${PORTSDIR}/graphics/graphviz \
		log4cpp.4:${PORTSDIR}/devel/log4cpp \
		vorbisfile.5:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USE_SCONS=	yes
SCONS_ARGS=	release=yes with_builtin_sdlnet=0
USE_SDL=	sdl net
WRKSRC=		${WRKDIR}/${PORTNAME}/FreeOrion

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freeorion* ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DATADIR}
	${CP} -R ${WRKSRC}/default ${DATADIR}
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

maint-gen-distfile:
	@if [ -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO_CMD} "ERROR: the distfile already exists."; \
		${FALSE}; \
	fi
	svn export https://svn.sourceforge.net/svnroot/${PORTNAME}/trunk ${PORTNAME}
	tar cjf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}
	${RM} -rf ${PORTNAME}

.include <bsd.port.mk>
