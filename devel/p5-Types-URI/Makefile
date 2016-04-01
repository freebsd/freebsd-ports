# $FreeBSD$

PORTNAME=	Types-URI
PORTVERSION=	0.006
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOBYINK
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for type constraints and coercions for URIs

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Type-Tiny>=1.000000:devel/p5-Type-Tiny \
	p5-Types-Path-Tiny>0:devel/p5-Types-Path-Tiny \
	p5-Type-Tiny>=0:devel/p5-Type-Tiny \
	p5-Types-UUID>=0:devel/p5-Types-UUID \
	p5-URI>0:net/p5-URI \
	p5-URI-FromHash>0:net/p5-URI-FromHash
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
