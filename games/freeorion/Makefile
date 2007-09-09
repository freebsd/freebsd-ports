# New ports collection makefile for:	freeorion
# Date created:				2007-04-29
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	freeorion
PORTVERSION=	0.3.1.20070909
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.alepulver.com.ar/distfiles/

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Open-source, platform independent galactic conquest game

LIB_DEPENDS=	GiGi.0:${PORTSDIR}/x11-toolkits/gigi \
		alut.1:${PORTSDIR}/audio/freealut \
		graph:${PORTSDIR}/graphics/graphviz \
		log4cpp.4:${PORTSDIR}/devel/log4cpp \
		vorbisfile.5:${PORTSDIR}/audio/libvorbis

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_SCONS=	yes
SCONS_ARGS=	-j 4 release=yes with_builtin_sdlnet=0
SCONS_BUILDENV=	PYTHON_LIB=${PYTHON_VERSION}
USE_SDL=	sdl net
WRKSRC=		${WRKDIR}/${PORTNAME}/FreeOrion

maint-gen-distfile:
	@if [ -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${ECHO_CMD} "ERROR: the distfile already exists."; \
		${FALSE}; \
	fi
	svn export https://${PORTNAME}.svn.sourceforge.net/svnroot/${PORTNAME}/trunk ${PORTNAME}
	tar cjf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}
	${RM} -rf ${PORTNAME}

.include <bsd.port.mk>
