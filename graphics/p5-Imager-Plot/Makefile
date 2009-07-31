# ex:ts=8
# Ports collection makefile for:	p5-Imager-Plot
# Date created:			Aug 31, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Imager-Plot
PORTVERSION=	0.09
PORTREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension for generating fancy graphic plots in color

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Imager.pm:${PORTSDIR}/graphics/p5-Imager
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Imager.pm:${PORTSDIR}/graphics/p5-Imager

PERL_CONFIGURE=	yes

MAN3=	Imager::Plot.3 Imager::Plot::Axis.3

.include <bsd.port.mk>
