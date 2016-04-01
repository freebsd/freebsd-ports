# $FreeBSD$

PORTNAME=	App-scan_prereqs_cpanfile
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for scanning prerequisite modules to generate cpanfile

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Module-CPANfile>=0.9020:devel/p5-Module-CPANfile \
	p5-Perl-PrereqScanner-Lite>=0.21:devel/p5-Perl-PrereqScanner-Lite
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuildtiny
NO_ARCH=	YES

.include <bsd.port.mk>
