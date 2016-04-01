# $FreeBSD$

PORTNAME=	TryCatch
PORTVERSION=	1.003002
PORTREVISION=	1
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ASH
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	First class try catch semantics for Perl, without source filters

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0.302:devel/p5-ExtUtils-Depends
RUN_DEPENDS=	p5-B-Hooks-EndOfScope>=0.08:devel/p5-B-Hooks-EndOfScope \
		p5-B-Hooks-OP-Check>=0.18:devel/p5-B-Hooks-OP-Check \
		p5-B-Hooks-OP-PPAddr>=0.03:devel/p5-B-Hooks-OP-PPAddr \
		p5-Devel-Declare>=0.005007:devel/p5-Devel-Declare \
		p5-Moose>=0:devel/p5-Moose \
		p5-MooseX-Types>=0:devel/p5-MooseX-Types \
		p5-Parse-Method-Signatures>=1.003012:devel/p5-Parse-Method-Signatures \
		p5-Scope-Upper>=0.06:devel/p5-Scope-Upper \
		p5-Sub-Exporter>=0.979:devel/p5-Sub-Exporter \
		p5-Variable-Magic>=0.28:devel/p5-Variable-Magic
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

OPTIONS_DEFINE=	AUTHOR

AUTHOR_DESC=	Include dependencies for AUTHORING

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAUTHOR}
BUILD_DEPENDS+=	p5-B-Hooks-OP-Check>=0.18:devel/p5-B-Hooks-OP-Check \
		p5-B-Hooks-OP-PPAddr>=0.03:devel/p5-B-Hooks-OP-PPAddr
.endif

.include <bsd.port.mk>
