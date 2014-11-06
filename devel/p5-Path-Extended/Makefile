# $FreeBSD$

PORTNAME=	Path-Extended
PORTVERSION=	0.22
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ISHIGAKI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for yet another Path class

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-File-Copy-Recursive>0:${PORTSDIR}/devel/p5-File-Copy-Recursive \
	p5-File-Find-Rule>0:${PORTSDIR}/devel/p5-File-Find-Rule \
	p5-Log-Dump>0:${PORTSDIR}/devel/p5-Log-Dump \
	p5-Sub-Install>0:${PORTSDIR}/devel/p5-Sub-Install
BUILD_DEPENDS=	${RUN_DEPENDS} \
	p5-ExtUtils-MakeMaker-CPANfile>0:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker-CPANfile

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
