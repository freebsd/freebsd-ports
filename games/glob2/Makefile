# New ports collection makefile for:	glob2
# Date created:		Wed 21 apr 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=		glob2
PORTVERSION=		0.9.4.4
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTVERSION:R}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Globulation 2 - a free and innovative strategy game

LIB_DEPENDS=		vorbis.4:${PORTSDIR}/audio/libvorbis		\
			speex.1:${PORTSDIR}/audio/speex			\
			fribidi.3:${PORTSDIR}/converters/fribidi	\
			boost_thread.4:${PORTSDIR}/devel/boost-libs	\
			freetype.9:${PORTSDIR}/print/freetype2
# Should work with portaudio v19_20071207
# Can be built with portaudio2 but does not run cleanly
#LIB_DEPENDS+=		portaudio.2:${PORTSDIR}/audio/portaudio2

USE_SDL=		image net sdl ttf
USE_GL=			gl
USE_GMAKE=		yes
USE_SCONS=		yes
#SCONS_ARGS=		--portaudio=true
INSTALLS_ICONS=		yes
SCONS_BUILDENV=		${SCONS_ENV}
#CFLAGS+=		${PTHREAD_CFLAGS} -I. `pkg-config --cflags portaudio-2.0` -I${LOCALBASE}/include
CFLAGS+=		${PTHREAD_CFLAGS} -I. -I${LOCALBASE}/include
#LINKFLAGS=		${PTHREAD_LIBS} `pkg-config --libs portaudio-2.0` -L${LOCALBASE}/lib
LINKFLAGS=		${PTHREAD_LIBS} -L${LOCALBASE}/lib

LICENSE=		GPLv3

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

manual-regression-test:
# Don't enable these tests on pointyhat, they take too long.
.if defined(MAINTAINER_MODE)
	(cd ${WRKSRC}/src && ./glob2 -test-games)
.else
	(cd ${WRKSRC}/src && ./glob2 -test-games-nox)
.endif

.include <bsd.port.mk>
