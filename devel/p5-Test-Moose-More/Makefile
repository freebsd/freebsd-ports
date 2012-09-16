# $FreeBSD$

PORTNAME=	Test-Moose-More
PORTVERSION=	0.011
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Test
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	More tools for testing Moose packages

BUILD_DEPENDS=	p5-Data-OptList>=0:${PORTSDIR}/devel/p5-Data-OptList \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Sub-Exporter>=0:${PORTSDIR}/devel/p5-Sub-Exporter
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Test::Moose::More.3

.include <bsd.port.mk>
