# $FreeBSD$

PORTNAME=	Jonk
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NEKOKAK
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for simple job tank manager

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-DBI>0:databases/p5-DBI \
	p5-Try-Tiny>0:lang/p5-Try-Tiny

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
