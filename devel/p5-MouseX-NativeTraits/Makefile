# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MouseX-NativeTraits
PORTVERSION=	1.09
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extend your attribute interfaces for Mouse

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Mouse>=0.82:devel/p5-Mouse
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Any-Moose>=0.13:devel/p5-Any-Moose \
		p5-Test-Fatal>=0.003:devel/p5-Test-Fatal

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
