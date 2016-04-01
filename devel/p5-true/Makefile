# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	true
PORTVERSION=	0.18
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CHOCOLATE
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatically return a true value when a file is required

BUILD_DEPENDS=	p5-B-Hooks-OP-Annotation>=0.43:devel/p5-B-Hooks-OP-Annotation \
		p5-B-Hooks-OP-Check>=0.18:devel/p5-B-Hooks-OP-Check \
		p5-Devel-StackTrace>=1.27:devel/p5-Devel-StackTrace \
		p5-ExtUtils-Depends>=0.304:devel/p5-ExtUtils-Depends
RUN_DEPENDS=	p5-B-Hooks-OP-Annotation>=0.43:devel/p5-B-Hooks-OP-Annotation \
		p5-B-Hooks-OP-Check>=0.18:devel/p5-B-Hooks-OP-Check \
		p5-Devel-StackTrace>=1.27:devel/p5-Devel-StackTrace

USE_PERL5=	configure
USES=		perl5

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/true/true.so

.include <bsd.port.mk>
