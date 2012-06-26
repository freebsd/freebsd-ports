# New ports collection makefile for:	expedite
# Date created:			10 March 2012
# Whom:				Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	expedite
DISTVERSION=	1.1.0
CATEGORIES=	benchmarks enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2011-12-02/base/

MAINTAINER=	magik@roorback.net
COMMENT=	Expedite is a benchmark suite for Evas

LICENSE=	BSD

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	evas
USE_EFL_EVAS_ENGINES=	buffer
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

OPTIONS=		OPENGL	"Enable OpenGL engine"	on \
			SDL	"Enable SDL engine"	off \
			X11	"Enable X11 engine"	on

.if !defined(WITHOUT_OPENGL)
USE_EFL_EVAS_ENGINES+=	opengl
CONFIGURE_ARGS+=	--enable-opengl-x11
.else
CONFIGURE_ARGS+=	--disable-opengl-x11
.endif

.if !defined(WITHOUT_SDL)
USE_EFL_EVAS_ENGINES+=	sdl
CONFIGURE_ARGS+=	--enable-software-sdl
.else
CONFIGURE_ARGS+=	--disable-software-sdl
.endif

.if !defined(WITHOUT_X11)
USE_EFL_EVAS_ENGINES+=	x11
CONFIGURE_ARGS+=	--enable-software-x11 --enable-xrender-x11
.else
CONFIGURE_ARGS+=	--disable-software-x11 --disable-xrender-x11
.endif

.include <bsd.port.mk>
