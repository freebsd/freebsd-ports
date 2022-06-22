# Created by: Alejandro Pulver <alejandro@varnet.biz>

PORTNAME=	tuxpaint
PORTVERSION=	0.9.28
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}-sdl2

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Drawing program designed for young children

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/docs/COPYING.txt

LIB_DEPENDS=	libfribidi.so:converters/fribidi \
		libpaper.so:print/libpaper \
		libimagequant.so:graphics/libimagequant \
		libpng16.so:graphics/png \
		libharfbuzz.so:print/harfbuzz

RUN_DEPENDS=	anytopnm:graphics/netpbm \
		bash:shells/bash

USES=		gettext gmake gnome gperf magick:7,build pkgconfig \
		python:3.7+ sdl shebangfix
SHEBANG_FILES=	src/tuxpaint-import.sh \
		fonts/locale/zh_tw_docs/maketuxfont.py

USE_GNOME=	librsvg2 cairo
USE_SDL=	gfx2 image2 mixer2 sdl2 ttf2
MAKE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PREFIX="${PREFIX}" \
		MAN_PREFIX="${STAGEDIR}${MANPREFIX}/man" \
		DEVMAN_PREFIX="${STAGEDIR}${MANPREFIX}/man" \
		X11_ICON_PREFIX="${STAGEDIR}${PREFIX}/share/pixmaps" \
		GNOME_PREFIX="${PREFIX}" \
		ARCH_INSTALL="" \
		OPTFLAGS="${CFLAGS} -DHAVE_STRCASESTR" \
		SHARED_FLAGS="-shared -fPIC" \
		GPERF="${GPERF}"

MAKE_JOBS_UNSAFE=	yes

INSTALL_TARGET=	install-gettext install-im install-magic-plugins \
		install-magic-plugin-dev install-default-config \
		install-example-stamps install-example-starters \
		install-icon install-bin install-importscript \
		install-data install-doc install-man

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} -r ${WRKSRC}/fonts/locale/vi_docs

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tuxpaint
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/tuxpaint/plugins/*.so

.include <bsd.port.mk>
