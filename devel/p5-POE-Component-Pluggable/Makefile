# Created by: chinsan
# $FreeBSD$

PORTNAME=	POE-Component-Pluggable
PORTVERSION=	1.26
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Base class for creating plugin enabled POE Components

BUILD_DEPENDS=	p5-POE>=1.004:devel/p5-POE \
		p5-Task-Weaken>=0:devel/p5-Task-Weaken
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
