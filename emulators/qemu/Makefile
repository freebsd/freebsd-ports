# New ports collection makefile for:	qemu
# Date created:			2004/05/31
# Whom:				Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	qemu
PORTVERSION=	0.5.5.s.20040530
CATEGORIES=	emulators
MASTER_SITES=	http://dad-answers.com/qemu/
DISTNAME=	${PORTNAME}-snapshot-2004-05-30_23-40

MAINTAINER=	nox@jelal.kn-bremen.de
COMMENT=	QEMU CPU Emulator

BUILD_DEPENDS+=	texi2html:${PORTSDIR}/textproc/texi2html

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
USE_GCC=	3.3
USE_PERL5=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
PATCH_STRIP=	-p1
CONFIGURE_ARGS+=	--cc=${CC}\ -fno-strict-aliasing\ -DDEBUG_IRQ_COUNT\ -I${PREFIX}/include --enable-slirp
MAN1=		qemu.1 qemu-mkcow.1

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
