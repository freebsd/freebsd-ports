# Created by: Mathieu Arnold <m@absolight.net>
# $FreeBSD$

PORTNAME=	DateTime-Format-Bork
PORTVERSION=	0.02
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Formats datetimes for that guy from The Muppet Show

RUN_DEPENDS=	p5-Params-Validate>=0:devel/p5-Params-Validate \
		p5-DateTime>=0:devel/p5-DateTime \
		p5-DateTime-Format-Builder>=0:devel/p5-DateTime-Format-Builder
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
