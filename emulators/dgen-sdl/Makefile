# New ports collection makefile for:	dgen-sdl
# Date created:				20 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dgen-sdl
PORTVERSION=	1.28
CATEGORIES=	emulators
MASTER_SITES=	SF/dgen/dgen/${PORTVERSION}

MAINTAINER=	spam@rm-rf.kiev.ua
COMMENT=	A wonderful Sega Genesis/MegaDrive emulator

USE_SDL=	sdl
USE_GL=		yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-extra-opt

PLIST_FILES=	bin/dgen \
		bin/dgen_tobin

MAN1=		dgen.1 dgen_tobin.1
MAN5=		dgenrc.5

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.else
CONFIGURE_ARGS+=	--disable-asm
.endif

.include <bsd.port.post.mk>
