# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Sys-Info-Driver-BSD
PORTVERSION=	0.7801
PORTREVISION=	1
CATEGORIES=	devel sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	BSD driver for Sys::Info

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-BSD-Sysctl>=0.08:sysutils/p5-BSD-Sysctl \
		p5-Sys-Info-Base>=0.7801:devel/p5-Sys-Info-Base \
		p5-Unix-Processors>=0:sysutils/p5-Unix-Processors
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=0:devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:devel/p5-Test-Pod-Coverage \
		p5-Test-Sys-Info>=0.20:devel/p5-Test-Sys-Info

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
