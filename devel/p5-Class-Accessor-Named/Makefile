# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Class-Accessor-Named
PORTVERSION=	0.009
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Better profiling output for Class::Accessor

RUN_DEPENDS=	p5-Sub-Name>=0:devel/p5-Sub-Name \
		p5-Class-Accessor>=0:devel/p5-Class-Accessor \
		p5-Hook-LexWrap>=0:devel/p5-Hook-LexWrap \
		p5-UNIVERSAL-require>=0:devel/p5-UNIVERSAL-require
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
