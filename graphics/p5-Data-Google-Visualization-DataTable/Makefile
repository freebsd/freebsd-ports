# $FreeBSD$

PORTNAME=	Data-Google-Visualization-DataTable
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Easily create Google DataTable objects for the Google Visulization API

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-JSON-XS>=2.0:converters/p5-JSON-XS

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
