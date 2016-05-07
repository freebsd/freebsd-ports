# $FreeBSD$

PORTNAME=	Test-PerlTidy
PORTVERSION=	20130104
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to check that all your files are tidy

RUN_DEPENDS=	\
	p5-File-Finder>0:devel/p5-File-Finder \
	p5-File-Slurp>0:devel/p5-File-Slurp \
	perltidy:devel/p5-Perl-Tidy \
	p5-Text-Diff>0:textproc/p5-Text-Diff
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
