# New ports collection makefile for:    gnat-glade
# Date created:         3 May 2000
# Whom:                 sam@inf.enst.fr
#
# $FreeBSD$
#

PORTNAME=	gnat-glade
PORTVERSION=	3.15p
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://cs.nyu.edu/pub/gnat/${PORTVERSION}/glade/
DISTNAME=	glade-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	sam@inf.enst.fr
COMMENT=	GNU Ada distributed systems annex

BUILD_DEPENDS=	adagcc:${PORTSDIR}/lang/gnat

USE_AUTOMAKE_VER=14
CONFIGURE_ENV=	ADA=adagcc
USE_GMAKE=	yes
USE_PERL5_BUILD=yes

pre-configure:
	${PERL} -pi -e "s@aclocal\)@${ACLOCAL})@g;\
			s@automake\)@${AUTOMAKE})@g" ${WRKSRC}/aclocal.m4

post-install:
	${STRIP_CMD} ${PREFIX}/bin/gnatdist

.include <bsd.port.mk>
