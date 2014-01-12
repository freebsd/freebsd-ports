# $FreeBSD$

PORTNAME=	MooseX-Types-Path-Tiny
PORTVERSION=	0.007
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of Path::Tiny types and coercions for Moose

RUN_DEPENDS=	\
	p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
	p5-MooseX-Types>0:${PORTSDIR}/devel/p5-MooseX-Types \
	p5-MooseX-Types-Stringlike>=0:${PORTSDIR}/devel/p5-MooseX-Types-Stringlike \
	p5-Path-Tiny>0:${PORTSDIR}/devel/p5-Path-Tiny
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	\
	p5-File-pushd>0:${PORTSDIR}/devel/p5-File-pushd \
	p5-Test-Fatal>0:${PORTSDIR}/devel/p5-Test-Fatal

USES=	perl5
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
