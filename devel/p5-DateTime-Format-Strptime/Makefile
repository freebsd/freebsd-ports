# Created by: Mathieu Arnold
# $FreeBSD$

PORTNAME=	DateTime-Format-Strptime
PORTVERSION=	1.56
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse and format strp and strf time patterns

LICENSE=	ART20

RUN_DEPENDS=	p5-DateTime>=1:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Locale>=0.45:${PORTSDIR}/devel/p5-DateTime-Locale \
		p5-DateTime-TimeZone>=0.79:${PORTSDIR}/devel/p5-DateTime-TimeZone \
		p5-Params-Validate>=0.64:${PORTSDIR}/devel/p5-Params-Validate
BUILD_DEPENDS:=	${RUN_DEPENDS}

PORTSCOUT=	skipv:1.0601,1.0700,1.0701,1.0702,1.0800,1.0900,1.0901,1.1000

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
