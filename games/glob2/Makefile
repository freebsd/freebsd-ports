# New ports collection makefile for:	glob2
# Date created:		Wed 21 apr 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=		glob2
PORTVERSION=		0.8.15
CATEGORIES=		games
MASTER_SITES=		http://epfl.ysagoon.com/~glob2/data/

MAINTAINER=		thierry@FreeBSD.org
COMMENT=		Globulation 2 - a free and innovative strategy game

LIB_DEPENDS=		vorbis.3:${PORTSDIR}/audio/libvorbis	\
			speex.3:${PORTSDIR}/audio/speex		\
			freetype.9:${PORTSDIR}/print/freetype2

USE_SDL=		image net sdl
USE_GL=			yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include"	\
			LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS} -L${LOCALBASE}/lib -L${X11BASE}/lib"
USE_GCC=		3.4
USE_REINPLACE=		yes

PLIST_FILES=		bin/glob2

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=			"Does not build on alpha"
.endif

pre-configure:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|"	\
		${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/glob2 ${PREFIX}/bin

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
