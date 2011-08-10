# New ports collection makefile for:	tuxpaint
# Date created:				14 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	tuxpaint
PORTVERSION=	0.9.21
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drawing program designed for young children

LIB_DEPENDS=	fribidi.3:${PORTSDIR}/converters/fribidi \
		paper.2:${PORTSDIR}/print/libpaper

USE_GNOME=	librsvg2
USE_SDL=	image mixer sdl ttf pango
USE_GETTEXT=	yes
USE_GMAKE=	yes
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

.if defined(NOPORTDOCS)
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
