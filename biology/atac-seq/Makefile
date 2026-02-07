PORTNAME=	atac-seq
DISTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	# empty

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Metaport for ATAC-Seq analysis
WWW=		https://github.com/auerlab/

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	sra-tools>0:biology/sra-tools \
		fastq-trim>0:biology/fastq-trim \
		fastqc>0:biology/fastqc \
		${PYTHON_PKGNAMEPREFIX}multiqc>0:biology/py-multiqc@${PY_FLAVOR} \
		biolibc-tools>0:biology/biolibc-tools \
		bwa>0:biology/bwa \
		bowtie2>0:biology/bowtie2 \
		samtools>0:biology/samtools \
		${PYTHON_PKGNAMEPREFIX}macs2>0:biology/py-macs2@${PY_FLAVOR} \
		fasda>0:biology/fasda \
		peak-classifier>0:biology/peak-classifier \
		webbrowser>0:www/webbrowser \
		curl>0:ftp/curl

USES=		metaport python

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MACS3>0:biology/py-macs3@${PY_FLAVOR}
.endif

.include <bsd.port.mk>
