# New ports collection makefile for:    kaffe
# Version required:     1.0.b1
# Date created:         20 February 1995
# Whom:                 Tim Wilkinson <tim@sarc.city.ac.uk>
#
# $Id: Makefile,v 1.32 1998/07/31 20:10:10 steve Exp $
#

DISTNAME=	kaffe-1.0.b1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.transvirtual.com/pub/kaffe/
DISTFILES=	${DISTNAME}.tar.gz

MAINTAINER=	xaa@xaa.iae.nl

LIB_DEPENDS=	jpeg\\.9\\.0:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
MAN1=		kaffe.1

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ENVIRONMENT ${PREFIX}/share/kaffe
	${INSTALL_DATA} ${WRKSRC}/license.terms ${PREFIX}/share/kaffe

.include <bsd.port.mk>
