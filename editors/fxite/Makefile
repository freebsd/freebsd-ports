PORTNAME=	fxite
DISTVERSIONPREFIX=	${PORTNAME:tu}-
DISTVERSION=	0_92
PORTREVISION=	4
CATEGORIES=	editors

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Advanced customizable graphical text editor
WWW=		https://github.com/yetanothergeek/fxite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libFOX-1.6.so:x11-toolkits/fox16

USES=		autoreconf desktop-file-utils gmake lua:52 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	yetanothergeek

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls --with-system-lua \
		--with-lua-pkg=lua-${LUA_VER}
CONFIGURE_ENV=	FOX_CFLAGS="$$(fox-config --cflags)" \
		FOX_LIBS="$$(fox-config --libs)" \
		RESWRAP="${LOCALBASE}/bin/reswrap"

PLIST_FILES=	bin/fxite \
		share/applications/fxite.desktop \
		share/pixmaps/fxite.xpm

post-patch:
	@${ECHO_CMD} 'AM_CPPFLAGS += $$(X11_CFLAGS)' \
		>> ${WRKSRC}/jef/Makefile.am

.include <bsd.port.mk>
