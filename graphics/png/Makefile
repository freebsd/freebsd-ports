# New ports collection makefile for:    PNG images library
# Date created:         5 Dec 1995
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	png
PORTVERSION=	1.0.5
CATEGORIES=     graphics
MASTER_SITES=   ftp://ftp.uu.net/graphics/png/src/
DISTNAME=       lib${PKGNAME}

MAINTAINER=     ache@FreeBSD.org

MAN3=           libpng.3 libpngpf.3
MAN5=           png.5

do-configure:
	cd ${WRKSRC} && ${CP} scripts/makefile.std Makefile

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
