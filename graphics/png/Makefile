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
PORTVERSION=    1.0.7
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.libpng.org/pub/png/src/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lib${PORTNAME}
DISTNAME=       lib${PKGNAME}

PATCH_SITES=    ftp://ftp.libpng.org/pub/png/src/
#PATCHFILES=

MAINTAINER=     ache@FreeBSD.org

INSTALLS_SHLIB=	yes

MAN3=           libpng.3 libpngpf.3
MAN5=           png.5

do-configure:
	cd ${WRKSRC} && ${CP} scripts/makefile.std Makefile

.include <bsd.port.mk>
