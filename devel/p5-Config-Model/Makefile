# Created by: ijliao
# $FreeBSD$

PORTNAME=	Config-Model
PORTVERSION=	2.107
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Model to create configuration validation tool

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Carp-Assert-More>=0:devel/p5-Carp-Assert-More \
		p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-Hash-Merge>=0.12:textproc/p5-Hash-Merge \
		p5-JSON>=0:converters/p5-JSON \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Log-Log4perl>=1.11:devel/p5-Log-Log4perl \
		p5-Mouse>=0:devel/p5-Mouse \
		p5-MouseX-NativeTraits>=0:devel/p5-MouseX-NativeTraits \
		p5-MouseX-StrictConstructor>=0:devel/p5-MouseX-StrictConstructor \
		p5-Parse-RecDescent>=1.90.0:devel/p5-Parse-RecDescent \
		p5-Path-Tiny>=0.70:devel/p5-Path-Tiny \
		p5-Pod-POM>=0:textproc/p5-Pod-POM \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-Term-ReadLine-Perl>=0:devel/p5-Term-ReadLine-Perl \
		p5-Text-Diff>=0:textproc/p5-Text-Diff \
		p5-Text-Levenshtein-Damerau>=0:devel/p5-Text-Levenshtein-Damerau
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Config-Model-Tester>=2.059:devel/p5-Config-Model-Tester \
		p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-File-Contents>=0:devel/p5-Test-File-Contents \
		p5-Test-Memory-Cycle>=0:devel/p5-Test-Memory-Cycle \
		p5-Test-Warn>=0.11:devel/p5-Test-Warn \
		p5-YAML>=0:textproc/p5-YAML \
		p5-YAML-Tiny>=0:textproc/p5-YAML-Tiny

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
