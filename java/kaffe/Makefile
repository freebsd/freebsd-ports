# New ports collection makefile for:    kaffe
# Date created:         20 February 1995
# Whom:                 Tim Wilkinson <tim@sarc.city.ac.uk>
#
# $FreeBSD$
#

PORTNAME=	kaffe
PORTVERSION=	1.0.6
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.kaffe.org/pub/kaffe/

MAINTAINER=	xaa+ports@madison-gurkha.com

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.4:${PORTSDIR}/graphics/png

USE_LIBTOOL=	yes
LIBTOOLFLAGS=
INSTALLS_SHLIB=	yes

MAN1=		kaffe.1

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/BUILD_ENVIRONMENT ${PREFIX}/share/kaffe
	${INSTALL_DATA} ${WRKSRC}/license.terms ${PREFIX}/share/kaffe

.include <bsd.port.mk>
