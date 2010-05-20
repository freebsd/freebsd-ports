# New ports collection makefile for:	p5-Geo-Point
# Date created:      			07 January 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Geo-Point
PORTVERSION=	0.93
CATEGORIES=	graphics devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Module Tries To Abstract Coordinate Systems

RUN_DEPENDS=	p5-Geo-Distance>=0.06:${PORTSDIR}/math/p5-Geo-Distance \
		p5-Geo-Proj4>=1.00:${PORTSDIR}/graphics/p5-Geo-Proj4 \
		p5-Math-Polygon>=1.00:${PORTSDIR}/math/p5-Math-Polygon

MAN3=		Geo::Point.3 Geo::Shape.3 Geo::Surface.3 \
		Geo::Line.3 Geo::Proj.3 Geo::Space.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
