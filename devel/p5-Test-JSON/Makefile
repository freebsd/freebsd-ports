# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-JSON
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${DISTVERSION:C/0$//}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Test JSON data

RUN_DEPENDS=	p5-Test-Differences>=0.47:devel/p5-Test-Differences \
		p5-JSON-Any>=1.20:converters/p5-JSON-Any
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 502200
BUILD_DEPENDS+=	p5-Test-Simple>=1.001.014:devel/p5-Test-Simple
RUN_DEPENDS+=	p5-Test-Simple>=1.001.014:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
