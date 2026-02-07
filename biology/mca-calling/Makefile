PORTNAME=	mca-calling
DISTVERSION=	0.1.0
CATEGORIES=	biology
MASTER_SITES=	# empty

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Core tools for Mosaic Chromosomal Alteration event calling
WWW=		https://github.com/auerlab/

LICENSE=	BSD2CLAUSE

RUN_DEPENDS+=	sra-tools>0:biology/sra-tools
RUN_DEPENDS+=	bcftools>0:biology/bcftools
RUN_DEPENDS+=	samtools>0:biology/samtools
RUN_DEPENDS+=	vcf-split>0:biology/vcf-split
RUN_DEPENDS+=	ad2vcf>0:biology/ad2vcf
RUN_DEPENDS+=	vcf2hap>0:biology/vcf2hap
RUN_DEPENDS+=	haplohseq>0:biology/haplohseq
RUN_DEPENDS+=	bio-mocha>0:biology/bio-mocha
RUN_DEPENDS+=	bedtools>0:biology/bedtools
RUN_DEPENDS+=	mawk>0:lang/mawk
RUN_DEPENDS+=	curl>0:ftp/curl
RUN_DEPENDS+=	liblz4>0:archivers/liblz4

USES=		metaport

.include <bsd.port.mk>
