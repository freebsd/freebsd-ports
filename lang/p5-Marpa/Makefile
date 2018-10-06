# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Marpa
PORTVERSION=	0.208
DISTVERSIONSUFFIX=	000
PORTREVISION=	1
CATEGORIES=	lang textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JKEGL
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parse any Language You Can Describe in BNF

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTML-Parser>=3.64:www/p5-HTML-Parser \
		p5-PPI>=1.206:textproc/p5-PPI

NO_ARCH=	yes
USE_PERL5=	modbuild
USES=		perl5

.include <bsd.port.mk>
