# New ports collection makefile for:	qemu
# Date created:			2004/05/31
# Whom:				Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	qemu
PORTVERSION=	0.6.1s.20041115
PORTREVISION=	0
CATEGORIES=	emulators
MASTER_SITES=	http://www.fruitsalad.org/qemu/ \
		http://dad-answers.com/qemu/
DISTNAME=	${PORTNAME}-snapshot-2004-11-15_23

MAINTAINER=	nox@jelal.kn-bremen.de
COMMENT=	QEMU CPU Emulator

BUILD_DEPENDS+=	texi2html:${PORTSDIR}/textproc/texi2html
RUN_DEPENDS+=	${LOCALBASE}/sbin/smbd:${PORTSDIR}/net/samba

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=	yes
USE_SDL=	sdl
USE_GCC=	3.4
USE_PERL5=	yes
PATCH_STRIP=	-p1
CONFIGURE_ARGS+=	--prefix=${PREFIX} --cc=${CC}\ -I${PREFIX}/include
MAN1=		qemu.1 qemu-img.1
ONLY_FOR_ARCHS=	i386 amd64 powerpc

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
