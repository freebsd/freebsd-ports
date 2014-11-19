# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	App-GitGot
PORTVERSION=	1.19
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:GENEHACK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tool to make it easier to manage multiple git repositories

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Config-INI>=0:${PORTSDIR}/devel/p5-Config-INI \
		p5-File-Copy-Recursive>=0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-Git-Wrapper>=0.014:${PORTSDIR}/devel/p5-Git-Wrapper \
		p5-Mouse>=0:${PORTSDIR}/devel/p5-Mouse \
		p5-MouseX-App-Cmd>=0:${PORTSDIR}/devel/p5-MouseX-App-Cmd \
		p5-MouseX-NativeTraits>=0:${PORTSDIR}/devel/p5-MouseX-NativeTraits \
		p5-Net-GitHub>=0:${PORTSDIR}/net/p5-Net-GitHub \
		p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
		p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Sort-Versions>=0:${PORTSDIR}/devel/p5-Sort-Versions \
		p5-Test-Class>=0:${PORTSDIR}/devel/p5-Test-Class \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-File>=0:${PORTSDIR}/devel/p5-Test-File

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
