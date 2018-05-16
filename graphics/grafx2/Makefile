# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grafx2
PORTVERSION=	2.5
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Pixelart-oriented bitmap painting program

LICENSE=	GPLv2

LIB_DEPENDS=	libX11.so:x11/libX11 \
		libpng.so:graphics/png

USES=		gmake pkgconfig tar:tgz iconv:wchar_t
USE_SDL=	sdl image
USE_GITLAB=	yes
GL_ACCOUNT=	GrafX2
GL_PROJECT=	grafX2
GL_COMMIT=	60b5e5fd50acb01cbdc59f50e2c8f4b8786635c0

WRKSRC_SUBDIR=	src
CFLAGS+=	-DHAVE_SYS_PARAM_H -DHAVE_SYS_UCRED_H -DHAVE_SYS_MOUNT_H

OPTIONS_DEFINE=	TTF LUA
TTF_DESC=	True Type font support
OPTIONS_DEFAULT=TTF

TTF_LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

# disable recoil support until we have a librecoil port
MAKE_ENV+=	NORECOIL=1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTTF}
USE_SDL+=	ttf
.else
MAKE_ARGS+=	NOTTF=1
.endif

.if ${PORT_OPTIONS:MLUA}
USES+=		lua:51 pkgconfig
.else
MAKE_ARGS+=	NOLUA=1
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|^  prefix = .*$$|  prefix = ${PREFIX}|' \
		-e '/scripts\/libs/d' \
		-e 's/CC = gcc/CC ?= gcc/' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
		-e 's|macosx|FreeBSD|g' \
		${WRKSRC}/mountlist.c ${WRKSRC}/init.c
	@${REINPLACE_CMD} \
		-e 's|Extract_path(program_dir, argv0);|strcpy(program_dir,"${PREFIX}/bin/");|' \
		${WRKSRC}/setup.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/grafx2

.include <bsd.port.mk>
