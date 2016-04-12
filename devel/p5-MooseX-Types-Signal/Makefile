# Created by: Denis Pokataev <catone@cpan.org>
# $FreeBSD$

PORTNAME=	MooseX-Types-Signal
PORTVERSION=	1.101932
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Type to represent valid UNIX or Perl signals

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-MooseX-Types>0:devel/p5-MooseX-Types
RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Test-Exception>0:devel/p5-Test-Exception \
		p5-Moose>0:devel/p5-Moose

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
