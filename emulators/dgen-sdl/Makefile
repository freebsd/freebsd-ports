# New ports collection makefile for:	dgen-sdl
# Date created:				20 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dgen-sdl
PORTVERSION=	1.23
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://pknet.com/~joe/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A wonderful Sega Genesis/MegaDrive emulator

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_SDL=	sdl
USE_GL=		yes
GNU_CONFIGURE=	yes

MAN1=		dgen.1 tobin.1
MAN5=		dgenrc.5

.include <bsd.port.mk>
