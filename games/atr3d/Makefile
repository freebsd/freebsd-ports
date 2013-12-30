# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	atr3d
PORTVERSION=	0.6
PORTREVISION=	14
CATEGORIES=	games
MASTER_SITES=	http://rodrigo.osorio.free.fr/freebsd/distfiles/
DISTNAME=	${PORTNAME}_source_${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	3D asteroids-like multiplayer game

OPTIONS_DEFINE=	OPENAL
OPTIONS_DEFAULT=OPENAL

SDL_CONFIG?=	${LOCALBASE}/bin/sdl-config

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake perl5
USE_GL=		glut glu
USE_XORG=	xmu xi x11
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"
USE_AUTOTOOLS=	automake autoconf

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib ${PTHREAD_LIBS}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENAL}
USES+=			openal:alut
CONFIGURE_ARGS+=	--enable-sound
.else
CONFIGURE_ARGS+=	--disable-sound
.endif

pre-patch:
	@${REINPLACE_CMD} -i '' -e 's|^aclocal|${ACLOCAL}|' \
			-e 's|^autoconf|${AUTOCONF}|' \
			-e  's|^automake|${AUTOMAKE}|' \
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

.include <bsd.port.mk>
