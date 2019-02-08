# Created by: Mathieu Arnold
# $FreeBSD$

PORTNAME=	DateTime-Format-Strptime
PORTVERSION=	1.76
PORTEPOCH=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Parse and format strp and strf time patterns

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DateTime>=1:devel/p5-DateTime \
		p5-DateTime-Locale>=1.23:devel/p5-DateTime-Locale \
		p5-DateTime-TimeZone>=2.09:devel/p5-DateTime-TimeZone \
		p5-Params-ValidationCompiler>=0:devel/p5-Params-ValidationCompiler \
		p5-Specio>=0.33:devel/p5-Specio \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-Test-Fatal>=0:devel/p5-Test-Fatal \
		p5-Test-Warnings>=0:devel/p5-Test-Warnings

PORTSCOUT=	skipv:1.0601,1.0700,1.0701,1.0702,1.0800,1.0900,1.0901,1.1000

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
