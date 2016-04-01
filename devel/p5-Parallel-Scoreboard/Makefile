# $FreeBSD$

PORTNAME=	Parallel-Scoreboard
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of scoreboard for monitoring status of many workers

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>=0.05:devel/p5-Class-Accessor-Lite \
	p5-HTML-Parser>0:www/p5-HTML-Parser \
	p5-JSON>0:converters/p5-JSON
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	YES

.include <bsd.port.mk>
