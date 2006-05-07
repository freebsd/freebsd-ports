# New ports collection makefile for:	atr3d
# Date created:				11 Jun 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	atr3d
PORTVERSION=	0.6
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.avoidtheroid.com/pub/${PORTNAME}/
DISTNAME=	${PORTNAME}_source_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D asteroids-like multiplayer game

LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal \
		glut.4:${PORTSDIR}/graphics/libglut \
		alut.0:${PORTSDIR}/audio/freealut

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-sound
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		SDL_CONFIG="${SDL_CONFIG}"
USE_AUTOTOOLS=	automake:14 autoconf:213

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}

pre-patch:
	@${PERL} -pi.orig -e 's|^aclocal|${ACLOCAL}|; \
		s|^autoconf|${AUTOCONF}|; s|^automake|${AUTOMAKE}|' \
		${WRKSRC}/autogen.sh
	@${REINPLACE_CMD} -e 's|-lopenal|& -lalut|' ${WRKSRC}/Makefile.am

pre-configure:
	cd ${WRKSRC}; ${SH} autogen.sh

post-configure:
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
