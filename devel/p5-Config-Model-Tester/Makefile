# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Config-Model-Tester
PORTVERSION=	2.055
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Test framework for Config::Model

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

# Do not add p5-Config-Model to TEST_DEPENDS to avoid cyclic dependency
BUILD_DEPENDS=	p5-File-Copy-Recursive>=0:devel/p5-File-Copy-Recursive \
		p5-Log-Log4perl>=1.11:devel/p5-Log-Log4perl \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-File-Contents>=0:devel/p5-Test-File-Contents \
		p5-Test-Memory-Cycle>=0:devel/p5-Test-Memory-Cycle \
		p5-Test-Warn>=0:devel/p5-Test-Warn
RUN_DEPENDS:=	${BUILD_DEPENDS}

CONFLICTS_INSTALL=	p5-Config-Model-2.0[0-3][0-9] p5-Config-Model-2.040

NO_ARCH=	yes
USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>
