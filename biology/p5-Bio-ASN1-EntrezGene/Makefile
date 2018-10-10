# Created by: Mauricio Herrera Cuadra <mauricio@arareko.net>
# $FreeBSD$

PORTNAME=	Bio-ASN1-EntrezGene
PORTVERSION=	1.73
PORTEPOCH=	1
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Regular expression-based Perl Parser for NCBI Entrez Gene

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-BioPerl>=0:biology/p5-BioPerl

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

post-patch:
# do not install Bio::SeqIO::entrezgene which is identical with the one from p5-BioPerl
	@${RM} ${WRKSRC}/lib/Bio/SeqIO/entrezgene.pm

.include <bsd.port.mk>
