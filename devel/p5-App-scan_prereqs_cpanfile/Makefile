# $FreeBSD$

PORTNAME=	App-scan_prereqs_cpanfile
PORTVERSION=	0.08
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for scanning prerequisite modules to generate cpanfile

RUN_DEPENDS=	\
	p5-Module-CPANfile>=0.9020:${PORTSDIR}/devel/p5-Module-CPANfile \
	p5-Perl-PrereqScanner>0:${PORTSDIR}/devel/p5-Perl-PrereqScanner
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
