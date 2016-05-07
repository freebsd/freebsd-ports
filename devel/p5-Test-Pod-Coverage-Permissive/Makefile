# Created by: andrey@kostenko.name
# $FreeBSD$

PORTNAME=	Test-Pod-Coverage-Permissive
PORTVERSION=	0.05
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Checks for pod coverage regression

RUN_DEPENDS=	p5-PathTools>=0:devel/p5-PathTools \
		p5-Pod-Coverage>=0:devel/p5-Pod-Coverage \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
