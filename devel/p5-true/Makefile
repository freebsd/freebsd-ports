# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	true
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CHOCOLATE
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatically return a true value when a file is required

BUILD_DEPENDS=	p5-ExtUtils-Depends>=0.405:devel/p5-ExtUtils-Depends \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-B-Hooks-OP-Annotation>=0.44:devel/p5-B-Hooks-OP-Annotation \
		p5-B-Hooks-OP-Check>=0.22:devel/p5-B-Hooks-OP-Check \
		p5-Devel-StackTrace>=1.27:devel/p5-Devel-StackTrace
TEST_DEPENDS=	p5-Function-Parameters>=2.001003:devel/p5-Function-Parameters \
		p5-Moo>=2.003004:devel/p5-Moo

USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/true/true.so

.include <bsd.port.mk>
