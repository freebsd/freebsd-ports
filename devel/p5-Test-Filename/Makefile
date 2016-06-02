# $FreeBSD$

PORTNAME=	Test-Filename
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for portable filename comparison

RUN_DEPENDS=	\
	p5-Path-Tiny>0:devel/p5-Path-Tiny
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
TEST_DEPENDS+=	p5-Test-Simple>=1.001014:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
