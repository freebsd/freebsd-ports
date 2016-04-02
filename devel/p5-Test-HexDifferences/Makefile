# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-HexDifferences
PORTVERSION=	1.000
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Test binary as hexadecimal string

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Test-Differences>=0.60:devel/p5-Test-Differences \
		p5-Test-NoWarnings>=0:devel/p5-Test-NoWarnings \
		p5-Text-Diff>=0:textproc/p5-Text-Diff
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.pre.mk>

# Test::Builder::Module 0.99+ (in core since 5.19.5) and
# Test::Tester (in core since 5.21.6) are required
.if ${PERL_LEVEL} < 502200
BUILD_DEPENDS+=	p5-Test-Simple>=0.99:devel/p5-Test-Simple
RUN_DEPENDS+=	p5-Test-Simple>=0.99:devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
