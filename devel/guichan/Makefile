# Created by: Tobias Gion <freebsd@gionet.de>
# $FreeBSD$

PORTNAME=	guichan
PORTVERSION=	0.8.2
PORTREVISION=	10
CATEGORIES=	devel games
MASTER_SITES=	http://pkgs.fedoraproject.org/repo/pkgs/guichan/guichan-0.8.2.tar.gz/af535d7f387e774e3197cef8023ea105/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, efficient C++ GUI library designed for games

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake pathfix libtool

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		SDL ALLEGRO OPENGL
OPTIONS_DEFAULT=	SDL OPENGL
ALLEGRO_DESC=	Allegro support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL}
USE_SDL+=	sdl image
CONFIGURE_ARGS+=--enable-sdl --enable-sdlimage
PLIST_SUB+=	SDL=""
.else
CONFIGURE_ARGS+=--disable-sdl --disable-sdlimage
PLIST_SUB+=	SDL="@comment "
.endif

.if ${PORT_OPTIONS:MALLEGRO}
LIB_DEPENDS+=	liballeg.so:devel/allegro
CONFIGURE_ARGS+=--enable-allegro
PLIST_SUB+=	ALLEGRO=""
.else
CONFIGURE_ARGS+=--disable-allegro
PLIST_SUB+=	ALLEGRO="@comment "
.endif

.if ${PORT_OPTIONS:MOPENGL}
USE_GL=		yes
CONFIGURE_ARGS+=--enable-opengl
PLIST_SUB+=	GL=""
.else
CONFIGURE_ARGS+=--disable-opengl
PLIST_SUB+=	GL="@comment "
.endif

.include <bsd.port.mk>
