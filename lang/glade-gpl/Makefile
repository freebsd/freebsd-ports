# New ports collection makefile for:    gnat-glade
# Date created:         3 Mai 2000
# Whom:                 sam@inf.enst.fr
#
# $FreeBSD$
#

PORTNAME= 	gnat-glade
PORTVERSION= 	3.12p
CATEGORIES=	lang
MASTER_SITES=	ftp://cs.nyu.edu/pub/gnat/glade/
DISTNAME=	glade-${PORTVERSION}-src

MAINTAINER=	sam@inf.enst.fr

BUILD_DEPENDS=	adagcc:${PORTSDIR}/lang/gnat

USE_AUTOCONF=	yes
CONFIGURE_ENV=	ADA=adagcc
USE_GMAKE=	yes

post-install:
	strip ${PREFIX}/bin/gnatdist

.include <bsd.port.mk>
