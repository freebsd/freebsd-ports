# Created by: gahr
# $FreeBSD$

PORTNAME=	fxite
DISTVERSIONPREFIX=	FXITE-
DISTVERSION=	0_92
PORTREVISION=	4
CATEGORIES=	editors

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced cross-platform text editor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	yetanothergeek

USES=		autoreconf desktop-file-utils gettext gmake lua pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-lua \
		--with-lua-pkg=lua-${LUA_VER}

CXXFLAGS+=	-fPIC
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

PLIST_FILES=	bin/fxite \
		share/applications/fxite.desktop \
		share/pixmaps/fxite.xpm

OPTIONS_SINGLE=		TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	FOX16 FOX17
OPTIONS_DEFAULT=	FOX16

FOX16_DESC=		Fox 1.6 GUI toolkit support
FOX16_LIB_DEPENDS=	libFOX-1.6.so:x11-toolkits/fox16
FOX16_CONFIGURE_ENV=	FOX_CFLAGS="$$(fox-config --cflags)" \
			FOX_LIBS="$$(fox-config --libs)" \
			RESWRAP="${LOCALBASE}/bin/reswrap"
FOX17_DESC=		Fox 1.7 GUI toolkit support
FOX17_LIB_DEPENDS=	libFOX-1.7.so:x11-toolkits/fox17
FOX17_CONFIGURE_ENV=	FOX_CFLAGS="$$(pkgconf fox17 --cflags)" \
			FOX_LIBS="$$(pkgconf fox17 --libs) -lX11" \
			RESWRAP="${LOCALBASE}/bin/fox-1.7/reswrap"
TOOLKIT_DESC=		GUI toolkit

.include <bsd.port.mk>
