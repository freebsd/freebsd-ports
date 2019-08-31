# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ExtUtils-CppGuess
PORTVERSION=	0.20
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Guess C++ compiler and flags

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny
TEST_DEPENDS=	p5-ExtUtils-CBuilder>=0.280231:devel/p5-ExtUtils-CBuilder

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502800
BUILD_DEPENDS+=	p5-ExtUtils-ParseXS>=3.35:devel/p5-ExtUtils-ParseXS
RUN_DEPENDS+=	p5-ExtUtils-ParseXS>=3.35:devel/p5-ExtUtils-ParseXS
.endif

.include <bsd.port.post.mk>
