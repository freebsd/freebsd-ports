# $FreeBSD$

PORTNAME=	AnyEvent-Filesys-Notify
PORTVERSION=	1.19
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MGRIMES
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for AnyEvent compat to monitor file/dir changes

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Moo>=1.003001:devel/p5-Moo \
	p5-MooX-late>=0.014:devel/p5-MooX-late \
	p5-MooX-Types-MooseLike>=0.25:devel/p5-MooX-Types-MooseLike \
	p5-AnyEvent>=7.05:devel/p5-AnyEvent \
	p5-Path-Iterator-Rule>=1.005:devel/p5-Path-Iterator-Rule \
	p5-Try-Tiny>=0.18:lang/p5-Try-Tiny \
	p5-namespace-autoclean>=0.24:devel/p5-namespace-autoclean \
	p5-IO-KQueue>=0.34:devel/p5-IO-KQueue
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Without-Module>=0:devel/p5-Test-Without-Module

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	YES

.include <bsd.port.mk>
