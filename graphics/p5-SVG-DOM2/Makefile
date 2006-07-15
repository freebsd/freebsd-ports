# New ports collection makefile for:	p5-SVG-DOM2
# Date created:		2006-07-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	SVG-DOM2
PORTVERSION=	1.00
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	SVG
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	SVG extention to the popular XML::DOM2

PERL_CONFIGURE=	yes

MAN3=		SVG::DOM2.3 SVG::DOM2::Attribute::Transform.3 \
		SVG::DOM2::Element::Document.3 SVG::DOM2::Element::Shape.3 \
		SVG::DOM2::Element::Shape::Fill.3 \
		SVG::DOM2::Element::Shape::Font.3 \
		SVG::DOM2::Element::Shape::Stroke.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
