# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Bio-Variation
PORTVERSION=	1.7.5
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	BioPerl variation-related functionality

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-BioPerl>=0:biology/p5-BioPerl \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-XML-Twig>=0:textproc/p5-XML-Twig \
		p5-XML-Writer>=0.400:textproc/p5-XML-Writer

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
