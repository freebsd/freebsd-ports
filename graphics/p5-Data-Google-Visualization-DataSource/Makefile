# $FreeBSD$

PORTNAME=	Data-Google-Visualization-DataSource
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl helper class for the Google Chart Tools Datasource Protocol

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Clone>=0:devel/p5-Clone \
		p5-Data-Google-Visualization-DataTable>=0:graphics/p5-Data-Google-Visualization-DataTable \
		p5-JSON-XS>=0:converters/p5-JSON-XS \
		p5-Moose>=0:devel/p5-Moose

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
