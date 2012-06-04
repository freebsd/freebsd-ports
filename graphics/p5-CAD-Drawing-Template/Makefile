# New ports collection makefile for:	CAD-Drawing-Template
# Date created:				22 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CAD-Drawing-Template
PORTVERSION=	0.01
PORTREVISION=	5
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Replace tags with text and geometry

BUILD_DEPENDS=	p5-CAD-Drawing>=0:${PORTSDIR}/graphics/p5-CAD-Drawing \
		p5-CAD-Calc>=0:${PORTSDIR}/math/p5-CAD-Calc
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN3=	CAD::Drawing::Template.3

PERL_MODBUILD=	yes

.include <bsd.port.mk>
