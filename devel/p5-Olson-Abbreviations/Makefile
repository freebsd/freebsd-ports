# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	Olson-Abbreviations
PORTVERSION=	0.04
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ECARROLL
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Globally unique timezones abbreviation handling

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-ClassAttribute>=0.25:devel/p5-MooseX-ClassAttribute \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
