# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	Geo-Point
PORTVERSION=	0.98
CATEGORIES=	graphics devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Module Tries To Abstract Coordinate Systems

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Geo-Distance>=0.06:math/p5-Geo-Distance \
		p5-Geo-Proj4>=1.01:graphics/p5-Geo-Proj4 \
		p5-Math-Polygon>=1.01:math/p5-Math-Polygon

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
