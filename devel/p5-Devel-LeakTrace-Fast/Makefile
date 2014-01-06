# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Devel-LeakTrace-Fast
PORTVERSION=	0.11
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Indicate where leaked variables are coming from

USES=		perl5
USE_PERL5=	configure

BROKEN=		does not compile under perl >= 5.12, see https://rt.cpan.org/Public/Bug/Display.html?id=56079

.include <bsd.port.mk>
