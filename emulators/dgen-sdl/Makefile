# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dgen-sdl
PORTVERSION=	1.32
CATEGORIES=	emulators
MASTER_SITES=	SF/dgen/dgen/${PORTVERSION}

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Wonderful Sega Genesis/MegaDrive emulator

USE_SDL=	sdl
USE_GL=		yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/dgen \
		bin/dgen_tobin

MAN1=		dgen.1 dgen_tobin.1
MAN5=		dgenrc.5

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == i386
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.else
CONFIGURE_ARGS+=	--disable-asm
.endif

.include <bsd.port.post.mk>
