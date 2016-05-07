# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	App-GitGot
PORTVERSION=	1.333
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Tool to make it easier to manage multiple git repositories

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-App-Cmd>=0:devel/p5-App-Cmd \
		p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		p5-Config-INI>=0:devel/p5-Config-INI \
		p5-Class-Load>=0:devel/p5-Class-Load \
		p5-File-Copy-Recursive>=0:devel/p5-File-Copy-Recursive \
		p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-File-chdir>=0:devel/p5-File-chdir \
		p5-Git-Wrapper>=0.042:devel/p5-Git-Wrapper \
		p5-IO-Prompt-Simple>=0:devel/p5-IO-Prompt-Simple \
		p5-List-AllUtils>=0.09:devel/p5-List-AllUtils \
		p5-Moo>=2:devel/p5-Moo \
		p5-MooX-HandlesVia>=0.001008:devel/p5-MooX-HandlesVia \
		p5-Net-GitHub>=0:net/p5-Net-GitHub \
		p5-Path-Tiny>=0.072:devel/p5-Path-Tiny \
		p5-PerlX-Maybe>=0:devel/p5-PerlX-Maybe \
		p5-Term-ANSIColor>=0:devel/p5-Term-ANSIColor \
		p5-Test-MockObject>=0:devel/p5-Test-MockObject \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-YAML>=0:textproc/p5-YAML \
		p5-namespace-autoclean>=0:devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Class>=0:devel/p5-Test-Class \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-File>=0:devel/p5-Test-File

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
