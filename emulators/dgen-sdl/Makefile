# New ports collection makefile for:	dgen-sdl
# Date created:				20 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dgen-sdl
PORTVERSION=	1.23
PORTREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	SF/dgen/dgen/sdl-${PORTVERSION} \
		http://tamentis.com/projects/dgen/files/ \
		http://launchpadlibrarian.net/10817989/:quilt
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		patches.tar.gz:quilt
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	spam@rm-rf.kiev.ua
COMMENT=	A wonderful Sega Genesis/MegaDrive emulator

NO_CDROM=	License only permits non-commercial use, modified versions of MZ80 are not allowed to be distributed
NO_PACKAGE=	${NO_CDROM}
RESTRICTED=	${NO_CDROM}
RESTRICTED_FILES=	patches.tar.gz

USE_SDL=	sdl
USE_GL=		yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-extra-opt

EXTRA_PATCHES=	${WRKDIR}/patches/fm-do-not-use-long.patch \
		${WRKDIR}/patches/mz80-pbPC-pointer-subtract.patch \
		${WRKDIR}/patches/mz80-stdint.patch \
		${WRKDIR}/patches/mz80init.patch \
		${WRKDIR}/patches/ras-emulate-pointer-wraparound.patch \
		${WRKDIR}/patches/sdl-use-stdint.patch

PLIST_FILES=	bin/dgen \
		bin/tobin

MAN1=		dgen.1 tobin.1
MAN5=		dgenrc.5

post-extract:
	@${REINPLACE_CMD} -e 's|^Index: dgen-|Index: ../dgen-sdl-|' ${WRKDIR}/patches/*

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif

.include <bsd.port.post.mk>
