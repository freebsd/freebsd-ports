# $FreeBSD$

PORTNAME=	MouseX-AttributeHelpers
PORTVERSION=	0.07
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MASAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to extend your attribute interfaces

RUN_DEPENDS=	\
	p5-Mouse>=0.40:devel/p5-Mouse
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Any-Moose>=0:devel/p5-Any-Moose \
		p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-UseAllModules>=0:devel/p5-Test-UseAllModules \
		p5-Test-Data>=0:devel/p5-Test-Data

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
