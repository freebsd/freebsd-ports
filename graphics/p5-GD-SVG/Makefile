# vim:ts=8
# New ports collection makefile for:	p5-GD-SVG
# Date created:				25 November 2004
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	GD-SVG
PORTVERSION=	0.33
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Seamlessly enable SVG output from scripts written using GD

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD \
		${SITE_PERL}/SVG.pm:${PORTSDIR}/textproc/p5-SVG

PERL_CONFIGURE=	5.8.0+	#inherited from graphics/p5-GD

MAN3=		GD::SVG.3

.include <bsd.port.mk>
