# New ports collection makefile for:    blender-static
# Date created:         14 November 2000
# Whom:                 Jimmy Olgeni <olgeni@uli.it>
#
# $FreeBSD$
#

PORTNAME=	blender
PORTVERSION=	2.04
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.blender.nl/pub/
DISTNAME=	blender${PORTVERSION}-freebsd-3.4-i386-static

MAINTAINER=     olgeni@uli.it

NO_CDROM=	"Commercial distribution prohibited"

USE_X_PREFIX=	YES

do-build:
	@echo "This is an install only port."

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/blender ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/blender
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/blender
	${INSTALL_DATA} ${WRKSRC}/copyright.txt ${PREFIX}/share/doc/blender

.include <bsd.port.mk>
