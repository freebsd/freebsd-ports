# $FreeBSD$

PORTNAME=	DBIx-Skinny-Mixin-DBHResolver
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of DBIx::DBHResolver mixin for DBIx::Skinny

RUN_DEPENDS=	\
	p5-DBIx-DBHResolver>0:databases/p5-DBIx-DBHResolver \
	p5-DBIx-Skinny>0:databases/p5-DBIx-Skinny
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
