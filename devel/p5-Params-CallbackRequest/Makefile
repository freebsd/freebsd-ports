# Created by: Rod Taylor <ports@rbt.ca>
# $FreeBSD$

PORTNAME=	Params-CallbackRequest
PORTVERSION=	1.20
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provide callbacks to method and function parameters

RUN_DEPENDS=	p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-Exception-Class>=0:devel/p5-Exception-Class \
		p5-Class-ISA>=0:devel/p5-Class-ISA
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
