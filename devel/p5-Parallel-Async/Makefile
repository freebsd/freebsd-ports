# $FreeBSD$

PORTNAME=	Parallel-Async
PORTVERSION=	0.03
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension to run parallel task with fork to simple

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>0:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
	p5-Try-Tiny>0:${PORTSDIR}/lang/p5-Try-Tiny
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild
PLIST_DIRS=	%%SITE_PERL%%/Parallel/Async %%SITE_PERL%%/Parallel

.include <bsd.port.mk>
