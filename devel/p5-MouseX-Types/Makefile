# $FreeBSD$

PORTNAME=	MouseX-Types
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GFUJI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to organize your Mouse types in libraries

RUN_DEPENDS=	\
	p5-Any-Moose>=0.15:devel/p5-Any-Moose \
	p5-Mouse>=0.77:devel/p5-Mouse
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
