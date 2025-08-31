PORTNAME=	grafx2
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9
DISTVERSIONSUFFIX=	.3219
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://pulkomandy.tk/projects/GrafX2/downloads/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Pixelart-oriented bitmap painting program
WWW=		https://pulkomandy.tk/projects/GrafX2

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libX11.so:x11/libX11

USES=		desktop-file-utils gmake gnome iconv:wchar_t pkgconfig sdl
USE_SDL=	image2 sdl2

MAKE_ENV+=	API=${GRAFX2_API} \
		V=1

CFLAGS+=	-DHAVE_SYS_PARAM_H -DHAVE_SYS_UCRED_H -DHAVE_SYS_MOUNT_H

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSIONPREFIX}${PORTVERSION}
WRKSRC_SUBDIR=	src

OPTIONS_DEFINE=		LUA TTF
OPTIONS_DEFAULT=	TTF
OPTIONS_SUB=		yes

TTF_DESC=	True Type font support

LUA_USES=		lua
LUA_MAKE_ARGS_OFF=	NOLUA=1
TTF_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
TTF_USE=		SDL=ttf2
TTF_MAKE_ARGS_OFF=	NOTTF=1

GRAFX2_API=	sdl2

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/grafx2-${GRAFX2_API} \
		${STAGEDIR}${PREFIX}/bin/grafx2
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/grafx2

.include <bsd.port.mk>
