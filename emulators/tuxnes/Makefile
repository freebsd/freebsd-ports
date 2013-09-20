# Created by: Jeroen Ruigrok van der Werven <asmodai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tuxnes
PORTVERSION=	0.75
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/TuxNES/TuxNES%20v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Nintendo Entertainment System 8-bit emulator

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	uses i386 assembly code

USE_XORG=	x11 ice sm xext xpm
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/romfixer bin/tuxnes

NO_STAGE=	yes
.include <bsd.port.mk>
