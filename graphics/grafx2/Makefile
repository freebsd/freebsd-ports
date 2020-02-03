# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grafx2
PORTVERSION=	2.7
DISTVERSIONSUFFIX=	.2945-src
CATEGORIES=	graphics
MASTER_SITES=	https://gitlab.com/GrafX2/grafX2/-/jobs/422881812/artifacts/raw/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Pixelart-oriented bitmap painting program

LICENSE=	GPLv2

LIB_DEPENDS=	libX11.so:x11/libX11 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		desktop-file-utils gmake gnome iconv:wchar_t pkgconfig sdl \
		tar:tgz
USE_SDL=	sdl2 image2

INSTALLS_ICONS=	yes

GRAFX2_API=	sdl2

WRKSRC=		${WRKDIR}/grafx2
WRKSRC_SUBDIR=	src
CFLAGS+=	-DHAVE_SYS_PARAM_H -DHAVE_SYS_UCRED_H -DHAVE_SYS_MOUNT_H
MAKE_ENV+=	API=${GRAFX2_API}

OPTIONS_DEFINE=	LUA TTF
OPTIONS_DEFAULT=TTF
OPTIONS_SUB=	yes
TTF_DESC=	True Type font support

LUA_USES=		lua
LUA_MAKE_ARGS_OFF=	NOLUA=1

TTF_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
TTF_USE=		SDL=ttf2
TTF_MAKE_ARGS_OFF=	NOTTF=1

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/grafx2-${GRAFX2_API} \
		${STAGEDIR}${PREFIX}/bin/grafx2
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/grafx2

.include <bsd.port.mk>
