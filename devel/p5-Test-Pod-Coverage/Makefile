# Created by: Lars Thegler <lth@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-Pod-Coverage
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Check for pod coverage in your distribution

LICENSE=	ART20

RUN_DEPENDS=	p5-Pod-Coverage>0:devel/p5-Pod-Coverage \
		p5-Test-Simple>0:devel/p5-Test-Simple
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
