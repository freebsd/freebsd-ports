# New ports collection makefile for:	CAD-Drawing-Template
# Date created:				22 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CAD-Drawing-Template
PORTVERSION=	0.01
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CAD
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Replace tags with text and geometry

BUILD_DEPENDS=	${SITE_PERL}/CAD/Drawing.pm:${PORTSDIR}/graphics/p5-CAD-Drawing \
		${SITE_PERL}/CAD/Calc.pm:${PORTSDIR}/math/p5-CAD-Calc
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	CAD::Drawing::Template.3

PERL_MODBUILD=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
