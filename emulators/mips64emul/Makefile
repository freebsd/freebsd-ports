# New ports collection makefile for:   mips64emul
# Date created:        05 June, 2004
# Whom:                Juli Mallett <jmallett@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mips64emul
PORTVERSION=	0.2
CATEGORIES=	emulators
MASTER_SITES=	http://www.mdstud.chalmers.se/~md1gavan/mips64emul/src/

MAINTAINER=	jmallett@FreeBSD.org
COMMENT=	A 64-bit MIPS emulator which emulates a variety of machines

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--nox11

PLIST_FILES=	bin/mips64emul

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mips64emul ${PREFIX}/bin/mips64emul

.include <bsd.port.mk>
