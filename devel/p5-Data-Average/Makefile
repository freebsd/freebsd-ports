# New ports collection makefile for:	p5-Data-Average
# Date created:	   01 Jun 2010
# Whom:		   Alexander Kriventsov <avk@vl.ru>
#
# $FreeBSD$
#

PORTNAME=	Data-Average
PORTVERSION=	0.03000
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	avk@vl.ru
COMMENT=	Hold Data Set To Calculate Average

BUILD_DEPENDS=	p5-UNIVERSAL-isa>=0:${PORTSDIR}/devel/p5-UNIVERSAL-isa
RUN_DEPENDS=	p5-UNIVERSAL-isa>=0:${PORTSDIR}/devel/p5-UNIVERSAL-isa

PERL_CONFIGURE=	yes

MAN3=	Data::Average::Bounded.3 Data::Average::BoundedExpires.3 Data::Average::Expires.3 Data::Average.3

.include <bsd.port.mk>
