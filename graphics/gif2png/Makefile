# New ports collection makefile for: gif2png
# Version required:    	1.1.1 
# Date created:         30 Aug 1999
# Whom:                 saper@system.pl
#
# $FreeBSD$
#

DISTNAME=       gif2png-1.1.1
CATEGORIES=	graphics
MASTER_SITES=   http://www.tuxedo.org/~esr/gif2png/

MAINTAINER=     saper@system.pl

LIB_DEPENDS=	png.3:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include"

pre-build:
		mv ${WRKSRC}/web2png ${WRKSRC}/web2png_prepatch
		$(SED) -e '1s#/usr/bin/python#/usr/bin/env python#' ${WRKSRC}/web2png_prepatch > ${WRKSRC}/web2png

MAN1=		gif2png.1 web2png.1

.include <bsd.port.mk>
