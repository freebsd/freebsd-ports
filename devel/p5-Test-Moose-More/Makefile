# $FreeBSD$

PORTNAME=	Test-Moose-More
PORTVERSION=	0.017
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	More tools for testing Moose packages

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-Data-OptList>=0:${PORTSDIR}/devel/p5-Data-OptList \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Moose-Autobox>=0:${PORTSDIR}/devel/p5-Moose-Autobox \
		p5-Perl6-Junction>=0:${PORTSDIR}/devel/p5-Perl6-Junction \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-TAP-SimpleOutput>=0:${PORTSDIR}/devel/p5-TAP-SimpleOutput \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::Moose::More.3

.include <bsd.port.mk>
