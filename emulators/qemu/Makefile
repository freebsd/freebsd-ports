# New ports collection makefile for:	qemu
# Date created:			2004/05/31
# Whom:				Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	qemu
PORTVERSION=	0.6.0s
CATEGORIES=	emulators
MASTER_SITES=	http://dad-answers.com/qemu/FreeBSD/
DISTNAME=	${PORTNAME}-snapshot-2004-07-15_23

MAINTAINER=	nox@jelal.kn-bremen.de
COMMENT=	QEMU CPU Emulator

BUILD_DEPENDS+=	texi2html:${PORTSDIR}/textproc/texi2html

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=	yes
USE_SDL=	sdl
USE_GCC=	3.3
USE_PERL5=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
PATCH_STRIP=	-p1
CONFIGURE_ARGS+=	--prefix=${PREFIX} --cc=${CC}\ -I${PREFIX}/include
MAN1=		qemu.1 qemu-mkcow.1
ONLY_FOR_ARCHS=	i386 amd64 powerpc

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
