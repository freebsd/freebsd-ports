# New ports collection makefile for:    gnat-glade
# Date created:         3 May 2000
# Whom:                 sam@inf.enst.fr
#
# $FreeBSD$
#

PORTNAME=	gnat-glade
PORTVERSION=	3.13p
CATEGORIES=	lang
MASTER_SITES=	ftp://cs.nyu.edu/pub/gnat/${PORTVERSION}/glade/
DISTNAME=	glade-${PORTVERSION}-src

MAINTAINER=	sam@inf.enst.fr

BUILD_DEPENDS=	adagcc:${PORTSDIR}/lang/gnat

USE_AUTOMAKE_VER=14
CONFIGURE_ENV=	ADA=adagcc
USE_GMAKE=	yes

pre-configure:
	${PERL} -pi -e "s@aclocal\)@${ACLOCAL})@g;\
			s@automake\)@${AUTOMAKE})@g" ${WRKSRC}/aclocal.m4

post-install:
	strip ${PREFIX}/bin/gnatdist

.include <bsd.port.mk>
