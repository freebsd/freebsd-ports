# Ports collection makefile for:	metapixel
# Date created:			2002-05-23
# Whom:				Tilman Linneweh <freebsdports@arved.de>
#
# $FreeBSD$

PORTNAME=	metapixel
PORTVERSION=	0.7
CATEGORIES=	graphics
MASTER_SITES=	http://www.complang.tuwien.ac.at/~schani/metapixel/

MAINTAINER=	freebsdports@arved.de

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_GMAKE=	yes

post-patch:
	@${RM} ${WRKSRC}/getopt.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/metapixel ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/metapixel-prepare ${PREFIX}/bin

.include <bsd.port.mk>
