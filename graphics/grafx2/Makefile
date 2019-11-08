# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grafx2
PORTVERSION=	2.6
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/recoil/recoil/${RECOIL_VERSION}/:recoil
DISTFILES=	recoil-${RECOIL_VERSION}${EXTRACT_SUFX}:recoil

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Pixelart-oriented bitmap painting program

LICENSE=	GPLv2

LIB_DEPENDS=	libX11.so:x11/libX11 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		desktop-file-utils gmake gnome iconv:wchar_t pkgconfig sdl
USE_SDL=	sdl2 image2
USE_GITLAB=	yes

GL_ACCOUNT=	GrafX2
GL_PROJECT=	grafX2
GL_COMMIT=	5d8c61e41011a8106359343243e1050af4e7fd1f

INSTALLS_ICONS=	yes

GRAFX2_API=	sdl2
RECOIL_VERSION=	4.3.1

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

post-extract:
	@${MV} ${WRKDIR}/recoil-${RECOIL_VERSION} ${WRKSRC}/../3rdparty/

post-patch:
	@${REINPLACE_CMD} \
		-e 's|macosx|FreeBSD|g' \
		${WRKSRC}/mountlist.c ${WRKSRC}/init.c
	@${REINPLACE_CMD} \
		-e 's|Extract_path(program_dir, argv0);|strcpy(program_dir,"${PREFIX}/bin/");|' \
		${WRKSRC}/setup.c

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/bin/grafx2-${GRAFX2_API} \
		${STAGEDIR}${PREFIX}/bin/grafx2
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/grafx2

.include <bsd.port.mk>
