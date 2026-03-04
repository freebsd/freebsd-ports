PORTNAME=	rna-seq
# Update major version only if the metaport is overhauled
# Update minor version when adding or removing dependencies
# Update revision for all other changes
DISTVERSION=	0.2.0
CATEGORIES=	biology python
MASTER_SITES=	# empty

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Metaport for RNA-Seq analysis
WWW=		https://github.com/auerlab/

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	sra-tools>0:biology/sra-tools \
		fastq-trim>0:biology/fastq-trim \
		fastqc>0:biology/fastqc \
		${PYTHON_PKGNAMEPREFIX}multiqc>0:biology/py-multiqc@${PY_FLAVOR} \
		biolibc-tools>0:biology/biolibc-tools \
		gffread>0:biology/gffread \
		kallisto>0:biology/kallisto \
		hisat2>0:biology/hisat2 \
		rna-STAR>0:biology/star \
		samtools>0:biology/samtools \
		fasda>0:biology/fasda \
		fasda-utils>0:biology/fasda-utils \
		webbrowser>0:www/webbrowser \
		curl>0:ftp/curl

USES=		metaport python

.include <bsd.port.mk>
