# New ports collection makefile for:    PNG images library
# ftp://ftp.libpng.org/pub/png/libpng.html
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $FreeBSD$
#
# PLEASE update print/ghostscript5 (there's a symlink that uses a hardwired
# png version number) when updating this port.  Thank you.

PORTNAME=	png
PORTVERSION=    1.0.8
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.libpng.org/pub/png/src/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lib${PORTNAME}
DISTNAME=       lib${PKGNAME}

PATCH_SITES=    ftp://ftp.libpng.org/pub/png/src/
#PATCHFILES=

MAINTAINER=     ache@FreeBSD.org

INSTALLS_SHLIB=	yes
SHLIB_VER=	4

MAKE_ENV=	SHLIB_VER="${SHLIB_VER}"
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

MAN3=           libpng.3 libpngpf.3
MAN5=           png.5

.include <bsd.port.pre.mk>

.if defined(WITH_MMX) && (${ARCH} == "i386")
MAKE_ENV+=	USE_MMX=yes
.endif

.if !defined(WITH_MMX) && (${ARCH} == "i386")
post-extract:
	@${ECHO_MSG}
	@${ECHO_MSG} " If you have a CPU with MMX instruction set (Pentium/P55C and higher) you can"
	@${ECHO_MSG} " try to add \"-DWITH_MMX\" to build libpng with MMX-optimized assembler routines."
	@${ECHO_MSG}
.endif

do-configure:
	${LN} -sf ${WRKSRC}/scripts/makefile.std ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
