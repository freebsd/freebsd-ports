# ex:ts=8
# Ports collection makefile for:	GDB 5.1 PowerPC simulator
# Date created:				12 October 2001
# Whom:					Mark Peek <mp@FreeBSD.org>
# 					David O'Brien <obrien@NUXI.com>
# $FreeBSD$
#

SNAPDATE=	2002-04-09
SNAPVER=	${SNAPDATE:S/-//g}

PORTNAME=	psim-freebsd
PORTVERSION=	5.2
PORTREVISION=	${SNAPVER}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
#MASTER_SITE_SUBDIR=	gdb/releases
MASTER_SITE_SUBDIR=	gdb/snapshots/branch
DISTNAME=	gdb+dejagnu-weekly-5.1.90_${SNAPVER}

MAINTAINER=	mp@FreeBSD.org

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-psim --target=powerpc-freebsd-elf \
		--program-suffix=psim
WRKSRC=		${WRKDIR}/gdb+dejagnu-5.1.90_${SNAPVER}

pre-configure:
	@cd ${WRKSRC} ; ${RM} -rf dejagnu expect tcl texinfo

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
	    | grep gdb+dejagnu-

.include <bsd.port.mk>
