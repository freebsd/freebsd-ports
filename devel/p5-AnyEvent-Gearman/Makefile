# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	AnyEvent-Gearman
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Asynchronous Gearman client/worker module for AnyEvent applications

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Any-Moose>=0:devel/p5-Any-Moose \
		p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-Mouse>=0:devel/p5-Mouse \
		p5-MouseX-Foreign>=0:devel/p5-MouseX-Foreign \
		p5-Object-Container>=0:devel/p5-Object-Container \
		p5-Object-Event>=0:devel/p5-Object-Event
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
