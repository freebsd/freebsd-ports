# New ports collection makefile for:  GOGO-no-coda
# Date created:        01 July 1999
# Whom:                Yukihiro Nakai <Nacai@iname.com>
#
# $FreeBSD$
#

PORTNAME=	gogo
PORTVERSION=	2.39b
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://homepage1.nifty.com/herumi/soft/gogo2/src/
DISTNAME=	gogo239b
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very fast MP3 encoder using recent x86 processors' features

# More than version 0.98
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

USE_GMAKE=	yes
ALL_TARGET=	gogo

RESTRICTED=	Condition is not clear
ONLY_FOR_ARCHS=	i386

# A sample of heavily optimized CFLAGS(typically used with pgcc).
# Recommended ONLY for benchmarks.
# CFLAGS=-march=pentiumpro -O6 -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -foptimize-register-move -ffast-math -fdefer-pop -mfancy-math-387

.include <bsd.port.pre.mk>

pre-fetch:
.if !defined(WITH_THREADS)
	@${ECHO_MSG} "set WITH_THREADS to compile with linuxthreads."
	@${ECHO_MSG} "It would increase performance in SMP environment."
MAKE_ENV+=	"USE_MT=no"
.else
MAKE_ENV+=	"USE_MT=yes"
.if ${OSVERSION} >= 500035
LIB_DEPENDS=	lthread.3:${PORTSDIR}/devel/linuxthreads
.else
LIB_DEPENDS=	lthread.2:${PORTSDIR}/devel/linuxthreads
.endif
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gogo ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/cdda2mp3.bsd \
		${PREFIX}/bin/cdda2mp3.gogo
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/gogo
	${INSTALL_DATA} ${WRKSRC}/contrib/cdda2mp3.txt \
		${PREFIX}/share/doc/gogo/cdda2mp3.gogo.en
	${INSTALL_DATA} ${WRKSRC}/contrib/cdda2mp3.euc \
		${PREFIX}/share/doc/gogo/cdda2mp3.gogo.ja
.endif

.include <bsd.port.post.mk>
