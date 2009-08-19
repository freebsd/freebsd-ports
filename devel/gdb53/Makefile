# ex:ts=8
# Ports collection makefile for:	GDB 5.1
# Date created:				30 March 2001
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $FreeBSD$
#

PORTNAME=	gdb
PORTVERSION=	5.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE:S/$/:sw/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	gdb/old-releases/:sw obrien/:local
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:sw,local

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	Source level debugger - GNU GDB 5.3

LATEST_LINK=	gdb53
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-suffix=53

ONLY_FOR_ARCHS=	i386 alpha sparc64

USE_GCC=	3.4

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64" && ${OSVERSION} >= 700042
BROKEN=		Does not install: reports Unknown Architecture
.elif ${OSVERSION} >= 800000
BROKEN=		unsupported FreeBSD version
.endif

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect sim tcl texinfo
	${LN} -sf ${FILESDIR}/freebsd-uthread.c ${FILESDIR}/kvm-fbsd.c \
		${WRKSRC}/gdb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb \
		${PREFIX}/bin/${PORTNAME}${PORTVERSION:S/.//g}

cklatest:
	ncftpls \
	    ftp://mirrors.rcn.net/mirrors/sources.redhat.com/${MASTER_SITE_SUBDIR}/  \
	    | ${GREP} gdb+dejagnu-weekly

.include <bsd.port.post.mk>
