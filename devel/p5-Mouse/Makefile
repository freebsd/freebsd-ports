# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mouse
PORTVERSION=	1.11
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GFUJI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Moose minus the antlers

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-Test-Exception-LessClever>=0.005:${PORTSDIR}/devel/p5-Test-Exception-LessClever \
		p5-Test-Requires>=0.06:${PORTSDIR}/devel/p5-Test-Requires

MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure

MAN3=		Mouse.3 \
		Mouse::Exporter.3 \
		Mouse::Meta::Attribute.3 \
		Mouse::Meta::Class.3 \
		Mouse::Meta::Method.3 \
		Mouse::Meta::Method::Accessor.3 \
		Mouse::Meta::Method::Constructor.3 \
		Mouse::Meta::Method::Delegation.3 \
		Mouse::Meta::Method::Destructor.3 \
		Mouse::Meta::Module.3 \
		Mouse::Meta::Role.3 \
		Mouse::Meta::Role::Application.3 \
		Mouse::Meta::Role::Composite.3 \
		Mouse::Meta::Role::Method.3 \
		Mouse::Meta::TypeConstraint.3 \
		Mouse::Object.3 \
		Mouse::PurePerl.3 \
		Mouse::Role.3 \
		Mouse::Spec.3 \
		Mouse::Tiny.3 \
		Mouse::TypeRegistry.3 \
		Mouse::Util.3 \
		Mouse::Util::MetaRole.3 \
		Mouse::Util::TypeConstraints.3 \
		Mouse::XS.3 \
		Squirrel.3 \
		Squirrel::Role.3 \
		Test::Mouse.3 \
		ouse.3

post-install:
	@${CAT} ${PKGDIR}/pkg-message

.include <bsd.port.mk>
