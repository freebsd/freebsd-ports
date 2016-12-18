# Created by: Mauricio Herrera Cuadra <mauricio@arareko.net>
# $FreeBSD$

PORTNAME=	Bio-ASN1-EntrezGene
PORTVERSION=	1.72
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Regular expression-based Perl Parser for NCBI Entrez Gene

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-BioPerl>=0:biology/p5-BioPerl
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
