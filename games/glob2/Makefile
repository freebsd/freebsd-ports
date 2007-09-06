# New ports collection makefile for:	glob2
# Date created:		Wed 21 apr 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=		glob2
PORTVERSION=		0.9.1
CATEGORIES=		games
MASTER_SITES=		http://dl.sv.nongnu.org/releases/glob2/${PORTVERSION}/
MASTER_SITE_SUBDIR=	thierry

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		Globulation 2 - a free and innovative strategy game

BUILD_DEPENDS=		${LOCALBASE}/include/boost/rational.hpp:${PORTSDIR}/devel/boost
LIB_DEPENDS=		vorbis.4:${PORTSDIR}/audio/libvorbis	\
			speex.1:${PORTSDIR}/audio/speex		\
			fribidi.0:${PORTSDIR}/converters/fribidi\
			freetype.9:${PORTSDIR}/print/freetype2

USE_SDL=		image net sdl ttf
USE_GL=			yes
USE_GMAKE=		yes
USE_SCONS=		yes
SCONS_BUILDENV=		${SCONS_ENV}
LINKFLAGS=		${PTHREAD_LIBS} -L${LOCALBASE}/lib -L${X11BASE}/lib
CFLAGS+=		${PTHREAD_CFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=			Does not build on ${ARCH}
.endif

pre-install:
	${CP} ${FILESDIR}/glob2.desktop ${WRKSRC}/data/

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
