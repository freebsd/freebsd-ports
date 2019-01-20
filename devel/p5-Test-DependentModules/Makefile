# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-DependentModules
PORTVERSION=	0.27
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Test all modules which depend on your module

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		p5-File-chdir>=0:devel/p5-File-chdir \
		p5-Parallel-ForkManager>=0.7.6:devel/p5-Parallel-ForkManager \
		p5-IO-Handle-Util>=0:devel/p5-IO-Handle-Util \
		p5-IPC-Run3>=0:devel/p5-IPC-Run3 \
		p5-Log-Dispatch>=0:devel/p5-Log-Dispatch \
		p5-MetaCPAN-Client>=0:devel/p5-MetaCPAN-Client \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-File-Copy-Recursive>=0:devel/p5-File-Copy-Recursive \
		p5-Module-Build>=0:devel/p5-Module-Build \
		p5-Module-Build-Tiny>=0:devel/p5-Module-Build-Tiny

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
