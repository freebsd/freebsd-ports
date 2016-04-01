# $FreeBSD$

PORTNAME=	Perl-PrereqScanner-Lite
PORTVERSION=	0.26
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for lightweight prereqs scanner

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Compiler-Lexer>=0.22:devel/p5-Compiler-Lexer \
	p5-Module-Path>0:devel/p5-Module-Path
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	YES

.include <bsd.port.mk>
