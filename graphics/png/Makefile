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
PORTVERSION=    1.0.6
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.libpng.org/pub/png/src/
DISTNAME=       lib${PKGNAME}

PATCH_SITES=    ftp://ftp.libpng.org/pub/png/src/
PATCHFILES=     libpng-1.0.6-patch-a.txt.gz \
		libpng-1.0.6-patch-b.txt.gz \
		libpng-1.0.6-patch-c.txt.gz

MAINTAINER=     ache@FreeBSD.org

MAN3=           libpng.3 libpngpf.3
MAN5=           png.5

do-configure:
	cd ${WRKSRC} && ${CP} scripts/makefile.std Makefile

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
