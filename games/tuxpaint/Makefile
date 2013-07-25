# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	tuxpaint
PORTVERSION=	0.9.21
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drawing program designed for young children

LIB_DEPENDS=	fribidi:${PORTSDIR}/converters/fribidi \
		paper:${PORTSDIR}/print/libpaper

OPTIONS_DEFINE=	DOCS

USE_GNOME=	librsvg2
USE_SDL=	image mixer sdl ttf pango
USES=		gettext gmake
MAKE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PREFIX="${PREFIX}" \
		DOC_PREFIX="${DOCSDIR}" \
		DEVDOC_PREFIX="${DOCSDIR}/dev" \
		MAN_PREFIX="${MANPREFIX}/man" \
		DEVMAN_PREFIX="${MANPREFIX}/man" \
		X11_ICON_PREFIX="${PREFIX}/share/pixmaps" \
		ARCH_INSTALL="" \
		OPTFLAGS="${CFLAGS} -DHAVE_STRCASESTR" \
		MAGIC_CFLAGS="${CFLAGS} -fno-common -Isrc `$(SDL_CONFIG) --cflags `" \
		SHARED_FLAGS="-shared -fPIC"

MANCOMPRESSED=	yes
MAN1=		tp-magic-config.1 tuxpaint.1 tuxpaint-import.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET=	install-bin install-data install-man install-magic-plugins \
		install-magic-plugin-dev install-icon install-gettext \
		install-im install-importscript install-default-config \
		install-example-stamps install-example-starters
.else
INSTALL_TARGET=	install-bin install-data install-man install-magic-plugins \
		install-magic-plugin-dev install-icon install-gettext \
		install-im install-importscript install-default-config \
		install-example-stamps install-example-starters install-doc
.endif

post-extract:
	@${RM} -rf ${WRKSRC}/fonts/locale/vi_docs

post-patch:
.for file in src/tuxpaint-import.sh src/tp_magic_api.h.in src/tuxpaint.conf \
	hildon/tuxpaint.conf
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
