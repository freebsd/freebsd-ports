# New ports collection makefile for:	qemu
# Date created:			2004/05/31
# Whom:				Juergen Lock <nox@jelal.kn-bremen.de>
#
# $FreeBSD$
#

PORTNAME=	qemu
PORTVERSION=	0.6.2s.20041228
PORTREVISION=	0
CATEGORIES=	emulators
MASTER_SITES=	http://people.fruitsalad.org/nox/qemu/ \
		http://dad-answers.com/qemu/
DISTNAME=	${PORTNAME}-snapshot-2004-12-28_23

MAINTAINER=	nox@jelal.kn-bremen.de
COMMENT=	QEMU CPU Emulator

BUILD_DEPENDS+=	texi2html:${PORTSDIR}/textproc/texi2html
RUN_DEPENDS+=	${LOCALBASE}/sbin/smbd:${PORTSDIR}/net/samba

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=	yes
USE_SDL=	sdl
USE_PERL5=	yes
PATCH_STRIP=	-p1
CONFIGURE_ARGS+=	--prefix=${PREFIX} --cc=${CC}\ -I${PREFIX}/include
MAN1=		qemu.1 qemu-img.1
ONLY_FOR_ARCHS=	i386 amd64 powerpc

# gcc34 (system cc on 5.x now) has problems with qemu:
# doesnt build target-i386/op.c on amd64, and builds a broken qemu-system-ppc
.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
CC=		gcc33
CXX=		g++33
BUILD_DEPENDS+=	gcc33:${PORTSDIR}/lang/gcc33
GCCVERSION=	030301
.else
USE_GCC=	3.3
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
