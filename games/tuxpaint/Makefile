# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	tuxpaint
PORTVERSION=	0.9.22
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drawing program designed for young children

LICENSE=	GPLv2 # (or later)
LICENSE_FILE=	${WRKSRC}/docs/COPYING.txt

LIB_DEPENDS=	libfribidi.so:${PORTSDIR}/converters/fribidi \
		libpaper.so:${PORTSDIR}/print/libpaper
RUN_DEPENDS=	anytopnm:${PORTSDIR}/graphics/netpbm \
		bash:${PORTSDIR}/shells/bash

USES=		gettext gmake gperf pkgconfig shebangfix
SHEBANG_FILES=	src/tuxpaint-import.sh
USE_GNOME=	librsvg2
USE_SDL=	image mixer sdl ttf pango
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

INSTALL_TARGET=	install-gettext install-im install-magic-plugins \
		install-magic-plugin-dev install-default-config \
		install-example-stamps install-example-starters \
		install-gnome install-icon install-bin install-importscript \
		install-data install-doc install-man

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} <= 901000
CFLAGS+=	-Dfmemopen_alternative
.endif

post-extract:
	@${CHMOD} -R a+rX ${WRKSRC}
	@${RM} -rf ${WRKSRC}/fonts/locale/vi_docs

post-patch:
.for file in src/tuxpaint-import.sh src/tp_magic_api.h.in src/tuxpaint.conf \
	hildon/tuxpaint.conf
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/${file}
.endfor

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tuxpaint
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/tuxpaint/plugins/*.so

.include <bsd.port.mk>
