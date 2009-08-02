# New ports collection makefile for:	guichan
# Date created:				2005-10-03
# Whom:					Tobias Gion <freebsd@gionet.de>
#
# $FreeBSD$
#

PORTNAME=	guichan
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	devel games
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A small, efficient C++ GUI library designed for games

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

OPTIONS=	SDL	"Enable SDL support" On \
		ALLEGRO	"Enable Allegro support" Off \
		GL	"Enable OpenGL support" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SDL)
USE_SDL+=	sdl image
CONFIGURE_ARGS+=--enable-sdl --enable-sdlimage
PLIST_SUB+=	SDL=""
.else
CONFIGURE_ARGS+=--disable-sdl --disable-sdlimage
PLIST_SUB+=	SDL="@comment "
.endif

.if defined(WITH_ALLEGRO)
LIB_DEPENDS+=	alleg.42:${PORTSDIR}/devel/allegro
CONFIGURE_ARGS+=--enable-allegro
PLIST_SUB+=	ALLEGRO=""
.else
CONFIGURE_ARGS+=--disable-allegro
PLIST_SUB+=	ALLEGRO="@comment "
.endif

.if !defined(WITHOUT_GL)
USE_GL=		yes
CONFIGURE_ARGS+=--enable-opengl
PLIST_SUB+=	GL=""
.else
CONFIGURE_ARGS+=--disable-opengl
PLIST_SUB+=	GL="@comment "
.endif

.include <bsd.port.post.mk>
