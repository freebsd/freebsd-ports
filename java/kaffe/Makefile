# New ports collection makefile for:    kaffe
# Version required:     1.0.b4
# Date created:         20 February 1995
# Whom:                 Tim Wilkinson <tim@sarc.city.ac.uk>
#
# $Id: Makefile,v 1.41 1999/04/10 01:41:01 archie Exp $
#

DISTNAME=	kaffe-1.0.b4
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.transvirtual.com/pub/kaffe/

MAINTAINER=	xaa@xaa.iae.nl

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		gif.3:${PORTSDIR}/graphics/giflib \
		png.3:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/kaffe-1.0b4
GNU_CONFIGURE=	yes
MAN1=		kaffe.1

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/BUILD_ENVIRONMENT ${PREFIX}/share/kaffe
	${INSTALL_DATA} ${WRKSRC}/license.terms ${PREFIX}/share/kaffe

.include <bsd.port.mk>
