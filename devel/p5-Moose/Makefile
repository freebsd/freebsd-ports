# New ports collection makefile for:	devel/p5-Moose
# Date created:				14 Apr 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Moose
PORTVERSION=	0.19
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/S/ST/STEVAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	A complete modern object system for Perl 5

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-Class-MOP>=0.37:${PORTSDIR}/devel/p5-Class-MOP \
	p5-Sub-Name>=0.02:${PORTSDIR}/devel/p5-Sub-Name \
	p5-Sub-Exporter>=0.972:${PORTSDIR}/devel/p5-Sub-Exporter

PERL_MODBUILD=	yes

MAN3=	Moose.3 \
	Moose::Cookbook.3 \
	Moose::Cookbook::FAQ.3 \
	Moose::Cookbook::Recipe1.3 \
	Moose::Cookbook::Recipe2.3 \
	Moose::Cookbook::Recipe3.3 \
	Moose::Cookbook::Recipe4.3 \
	Moose::Cookbook::Recipe5.3 \
	Moose::Cookbook::Recipe6.3 \
	Moose::Cookbook::WTF.3 \
	Moose::Meta::Attribute.3 \
	Moose::Meta::Class.3 \
	Moose::Meta::Instance.3 \
	Moose::Meta::Method.3 \
	Moose::Meta::Method::Accessor.3 \
	Moose::Meta::Method::Constructor.3 \
	Moose::Meta::Method::Destructor.3 \
	Moose::Meta::Method::Overriden.3 \
	Moose::Meta::Role.3 \
	Moose::Meta::Role::Method.3 \
	Moose::Meta::TypeCoercion.3 \
	Moose::Meta::TypeConstraint.3 \
	Moose::Meta::TypeConstraint::Union.3 \
	Moose::Object.3 \
	Moose::Role.3 \
	Moose::Util::TypeConstraints.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,Test::,' ${WRKSRC}/Build.PL

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>
