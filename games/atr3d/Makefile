# New ports collection makefile for:	atr3d
# Date created:				11 Jun 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	atr3d
PORTVERSION=	0.6
PORTREVISION=	14
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.avoidtheroid.com/pub/${PORTNAME}/
DISTNAME=	${PORTNAME}_source_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	3D asteroids-like multiplayer game

OPTIONS=	SOUND	"Enable sound"	ON

SDL_CONFIG?=	${LOCALBASE}/bin/sdl-config

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
USE_GL=		glut glu
USE_XORG=	xmu xi x11
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sound
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"
USE_AUTOTOOLS=	automake autoconf

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SOUND)
USE_OPENAL=		alut
CONFIGURE_ARGS+=	--enable-sound
.else
CONFIGURE_ARGS+=	--disable-sound
.endif

pre-patch:
	@${PERL} -pi.orig -e 's|^aclocal|${ACLOCAL}|; \
		s|^autoconf|${AUTOCONF}|; s|^automake|${AUTOMAKE}|' \
		${WRKSRC}/autogen.sh
	@${REINPLACE_CMD} -e 's|-lopenal|& -lalut|' ${WRKSRC}/Makefile.am

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' ${WRKSRC}/Makefile.am

pre-configure:
	cd ${WRKSRC}; ${SH} autogen.sh

post-configure:
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>
