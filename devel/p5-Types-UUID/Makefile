# $FreeBSD$

PORTNAME=	Types-UUID
PORTVERSION=	0.004
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOBYINK
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for type constraints for UUIDs

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Type-Tiny>=1.000000:devel/p5-Type-Tiny \
	p5-UUID-Tiny>=1.02:devel/p5-UUID-Tiny
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
