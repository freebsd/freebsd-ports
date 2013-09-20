# Created by: ijliao
# $FreeBSD$

PORTNAME=	Imager-Plot
PORTVERSION=	0.09
PORTREVISION=	5
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension for generating fancy graphic plots in color

BUILD_DEPENDS=	p5-Imager>=0:${PORTSDIR}/graphics/p5-Imager
RUN_DEPENDS=	p5-Imager>=0:${PORTSDIR}/graphics/p5-Imager

USES=		perl5
USE_PERL5=	configure

MAN3=	Imager::Plot.3 Imager::Plot::Axis.3

NO_STAGE=	yes
.include <bsd.port.mk>
