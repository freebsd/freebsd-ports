# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Test-DependentModules
PORTVERSION=	0.17
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Test all modules which depend on your module

LICENSE=	ART20

BUILD_DEPENDS=	p5-Capture-Tiny>=0:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-File-chdir>=0:${PORTSDIR}/devel/p5-File-chdir \
		p5-Parallel-ForkManager>=0.7.6:${PORTSDIR}/devel/p5-Parallel-ForkManager \
		p5-IO-Handle-Util>=0:${PORTSDIR}/devel/p5-IO-Handle-Util \
		p5-IPC-Run3>=0:${PORTSDIR}/devel/p5-IPC-Run3 \
		p5-Log-Dispatch>=0:${PORTSDIR}/devel/p5-Log-Dispatch \
		p5-MetaCPAN-API>=0:${PORTSDIR}/devel/p5-MetaCPAN-API \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-autodie>=0:${PORTSDIR}/devel/p5-autodie
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		p5-Module-Build-Tiny>=0:${PORTSDIR}/devel/p5-Module-Build-Tiny

PERL_CONFIGURE=	yes

MAN3=		Test::DependentModules.3

.include <bsd.port.mk>
