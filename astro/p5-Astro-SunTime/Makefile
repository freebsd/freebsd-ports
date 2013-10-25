# Created by: will
# $FreeBSD$

PORTNAME=	Astro-SunTime
PORTVERSION=	0.01
CATEGORIES=	astro perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Astro
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to calculate sunrise/sunset times

BUILD_DEPENDS=	p5-Time-modules>=0:${PORTSDIR}/devel/p5-Time-modules
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
