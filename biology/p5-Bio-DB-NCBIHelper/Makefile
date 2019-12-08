# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Bio-DB-NCBIHelper
PORTVERSION=	1.7.6
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Collection of routines useful for queries to NCBI databases

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Bio-ASN1-EntrezGene>=0:biology/p5-Bio-ASN1-EntrezGene \
		p5-BioPerl>=1.007007:biology/p5-BioPerl \
		p5-CGI>=0:www/p5-CGI \
		p5-Cache-Cache>=0:devel/p5-Cache-Cache \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-URI>=0:net/p5-URI \
		p5-XML-Twig>=0:textproc/p5-XML-Twig \
		p5-libwww>=0:www/p5-libwww
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Most>=0:devel/p5-Test-Most \
		p5-Test-RequiresInternet>=0:devel/p5-Test-RequiresInternet

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
