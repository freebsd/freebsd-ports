# $FreeBSD$

PORTNAME=	JSON-Pointer
PORTVERSION=	0.07
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of JSON Pointer (RFC6901)

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Class-Accessor-Lite>=0.05:devel/p5-Class-Accessor-Lite \
	p5-Clone>=0.36:devel/p5-Clone \
	p5-JSON>=2.53:converters/p5-JSON \
	p5-URI>=1.65:net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	YES

.include <bsd.port.mk>
