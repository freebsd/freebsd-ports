# New ports collection makefile for:	tiff2png
# Date created:				Tue 04 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	tiff2png
PORTVERSION=	0.81c
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.libpng.org/pub/png/src/ \
		ftp://swrinde.nde.swri.edu/pub/png/applications/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.4:${PORTSDIR}/graphics/png

MAKEFILE=	Makefile.unx
ALL_TARGET=	tiff2png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tiff2png ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/tiff2png
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tiff2png
.endif

.include <bsd.port.mk>
