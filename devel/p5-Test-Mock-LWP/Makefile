# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>
# $FreeBSD$

PORTNAME=	Test-Mock-LWP
PORTVERSION=	0.08
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easy mocking of LWP packages

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Test-MockObject>=1.08:devel/p5-Test-MockObject
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
