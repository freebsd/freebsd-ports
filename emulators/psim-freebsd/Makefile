# Created by: Mark Peek <mp@FreeBSD.org>
# $FreeBSD$

PORTNAME=	psim-freebsd
.if defined(WITHOUT_GPLv3)
PORTVERSION=	6.6
.else
PORTVERSION=	7.0.1
.endif
PORTREVISION?=	0
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR= gdb
DISTNAME=	gdb-${PORTVERSION}

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	PowerPC simulator (PSIM) running in the GNU GDB 6

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-psim --target=powerpc-freebsd-elf \
		--program-suffix=psim \
		--disable-nls

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/dot.gdbinit ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/HOW-TO ${DOCSDIR}
.endif

cklatest:
	ncftpls \
	    ftp://mirrors.rcn.net/mirrors/sources.redhat.com/${MASTER_SITE_SUBDIR}/  \
	    | ${GREP} gdb+dejagnu-

.include <bsd.port.mk>
