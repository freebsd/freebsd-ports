# ex:ts=8
# Ports collection makefile for:	GDB 5.1 PowerPC simulator
# Date created:				12 October 2001
# Whom:					Mark Peek <mp@FreeBSD.org>
# 					David O'Brien <obrien@NUXI.com>
# $FreeBSD$
#

PORTNAME=	psim-freebsd
PORTVERSION=	6.0
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	gdb/releases
DISTNAME=	gdb-${PORTVERSION}

MAINTAINER=	mp@FreeBSD.org
COMMENT=	PowerPC simulator (PSIM) running in the GNU GDB 6

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-psim --target=powerpc-freebsd-elf \
		--program-suffix=psim

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	${INSTALL_DATA} ${FILESDIR}/dot.gdbinit \
		${PREFIX}/share/examples/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/HOW-TO ${DOCSDIR}
.endif

cklatest:
	ncftpls \
	    ftp://mirrors.rcn.net/mirrors/sources.redhat.com/${MASTER_SITE_SUBDIR}/  \
	    | ${GREP} gdb+dejagnu-

.include <bsd.port.mk>
