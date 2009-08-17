# New ports collection makefile for:	graphics/p5-URI-GoogleChart
# Date created:				28 March 2009
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	URI-GoogleChart
PORTVERSION=	1.02
CATEGORIES=	graphics www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	URI
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Generate Google Chart URIs

BUILD_DEPENDS=	p5-URI>0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.6.0+

MAN3=	URI::GoogleChart.3

.include <bsd.port.mk>
