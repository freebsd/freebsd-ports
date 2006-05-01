# New ports collection makefile for:	devel/p5-Moose
# Date created:				14 Apr 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Moose
PORTVERSION=	0.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/S/ST/STEVAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	"Moose, it's the new Camel"

BUILD_DEPENDS=	${RUN_DEPENDS} \
	p5-Test-Simple>=0.47:${PORTSDIR}/devel/p5-Test-Simple \
	p5-Test-Exception>=0.21:${PORTSDIR}/devel/p5-Test-Exception
RUN_DEPENDS=	\
	p5-Scalar-List-Utils>=1.18:${PORTSDIR}/lang/p5-Scalar-List-Utils \
	p5-Class-MOP>=0.26:${PORTSDIR}/devel/p5-Class-MOP \
	p5-Sub-Name>=0.02:${PORTSDIR}/devel/p5-Sub-Name \
	p5-UNIVERSAL-require>=0.10:${PORTSDIR}/devel/p5-UNIVERSAL-require \
	p5-Sub-Exporter>=0.93:${PORTSDIR}/devel/p5-Sub-Exporter

PERL_MODBUILD=	yes

MAN3=	Moose.3 \
	Moose::Cookbook.3 \
	Moose::Cookbook::Recipe1.3 \
	Moose::Cookbook::Recipe2.3 \
	Moose::Cookbook::Recipe3.3 \
	Moose::Cookbook::Recipe4.3 \
	Moose::Cookbook::Recipe5.3 \
	Moose::Cookbook::Recipe6.3 \
	Moose::Meta::Attribute.3 \
	Moose::Meta::Class.3 \
	Moose::Meta::Role.3 \
	Moose::Meta::TypeCoercion.3 \
	Moose::Meta::TypeConstraint.3 \
	Moose::Object.3 \
	Moose::Role.3 \
	Moose::Util::TypeConstraints.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>
