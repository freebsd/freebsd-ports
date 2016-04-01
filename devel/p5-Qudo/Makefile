# $FreeBSD$

PORTNAME=	Qudo
PORTVERSION=	0.0213
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NEKOKAK
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for simple and extensible job queue manager

RUN_DEPENDS=	\
	p5-Class-Data-Inheritable>0:devel/p5-Class-Data-Inheritable \
	p5-DBI>0:databases/p5-DBI \
	p5-DBIx-Skinny>0:databases/p5-DBIx-Skinny \
	p5-UNIVERSAL-require>0:devel/p5-UNIVERSAL-require \
	p5-YAML>0:textproc/p5-YAML
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
