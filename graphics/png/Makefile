# New ports collection makefile for:    PNG images library
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	png
PORTVERSION=	1.0.9
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.libpng.org/pub/png/src/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lib${PORTNAME}
DISTFILES=	lib${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

#PATCH_SITES=	ftp://ftp.libpng.org/pub/png/src/
#PATCHFILES=

MAINTAINER=	ache@FreeBSD.org

WRKSRC=		${WRKDIR}/lib${PORTNAME}-${PORTVERSION}

INSTALLS_SHLIB=	yes
SHLIB_VER=	4

MAKE_ENV=	SHLIB_VER="${SHLIB_VER}"
PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

MAN3=		libpng.3 libpngpf.3
MAN5=		png.5

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PNG_MMX) && (${ARCH} == "i386")
MAKE_ENV+=	USE_MMX=yes
.endif

post-extract:
# Please don't delete the following line - this link used by ghostscript* ports
	@${LN} -sf ${WRKSRC} ${WRKDIR}/libpng
#
.if !defined(WITHOUT_PNG_MMX) && (${ARCH} == "i386")
	@${ECHO_MSG}
	@${ECHO_MSG} " If you don't have a CPU with MMX instruction set (Pentium/P55C and higher) you"
	@${ECHO_MSG} " can add \"WITH_PNG_MMX=YES\" to /etc/make.conf to build libpng without"
	@${ECHO_MSG} " MMX-optimized assembler routines."
	@${ECHO_MSG}
.endif

do-configure:
	${LN} -sf ${WRKSRC}/scripts/makefile.std ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
