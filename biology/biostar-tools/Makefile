PORTNAME=	biostar-tools
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	# empty

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Meta-port for Biostar Handbook tools
WWW=		https://www.biostarhandbook.com

LICENSE=	BSD2CLAUSE

# For a current list see http://data.biostarhandbook.com/install/conda.txt.
# Also included are some programs not listed above, but mentioned in the text.
# TODO: Add hdfview
RUN_DEPENDS=	wget>0:ftp/wget \
		curl>0:ftp/curl \
		nano>0:editors/nano \
		parallel>0:sysutils/parallel \
		seqkit>0:biology/seqkit \
		csvtk>0:science/csvtk \
		${PYTHON_PKGNAMEPREFIX}csvkit>0:textproc/py-csvkit@${PY_FLAVOR} \
		miller>0:textproc/miller \
		ncbi-entrez-direct>0:biology/ncbi-entrez-direct \
		readseq>0:biology/readseq \
		snpeff>0:biology/snpeff \
		picard-tools>0:biology/picard-tools \
		bbmap>0:biology/bbmap \
		minimap2>0:biology/minimap2 \
		bwa>0:biology/bwa \
		bowtie2>0:biology/bowtie2 \
		samtools>0:biology/samtools \
		emboss>0:biology/emboss \
		bedtools>0:biology/bedtools \
		bamtools>0:biology/bamtools \
		${PYTHON_PKGNAMEPREFIX}cutadapt>0:biology/py-cutadapt@${PY_FLAVOR} \
		seqtk>0:biology/seqtk \
		datamash>0:textproc/datamash \
		bcftools>0:biology/bcftools \
		subread>0:biology/subread \
		hisat2>0:biology/hisat2 \
		trimmomatic>0:biology/trimmomatic \
		fastqc>0:biology/fastqc \
		picard-tools>0:biology/picard-tools \
		ncbi-blast+>0:biology/ncbi-blast+ \
		cd-hit>0:biology/cd-hit \
		${PYTHON_PKGNAMEPREFIX}biopython>0:biology/py-biopython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysam>0:biology/py-pysam@${PY_FLAVOR} \
		freebayes>0:biology/freebayes \
		p5-Net-SSLeay>0:security/p5-Net-SSLeay \
		bioawk>0:biology/bioawk \
		vt>0:biology/vt \
		${PYTHON_PKGNAMEPREFIX}crossmap>0:biology/py-crossmap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}goatools>0:biology/py-goatools@${PY_FLAVOR} \
		erminej>0:biology/erminej \
		${PYTHON_PKGNAMEPREFIX}ont-fast5-api>0:biology/py-ont-fast5-api@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multiqc>0:biology/py-multiqc@${PY_FLAVOR} \
		flash>0:biology/flash \
		bfc:biology/bfc \
		Jellyfish>0:biology/jellyfish \
		mafft>0:biology/mafft \
		clustal-omega>0:biology/clustal-omega \
		sam2pairwise>0:biology/sam2pairwise \
		kallisto>0:biology/kallisto \
		bamutil>0:biology/bamutil \
		${PYTHON_PKGNAMEPREFIX}deepTools>0:biology/py-deeptools@${PY_FLAVOR} \
		igv>0:biology/igv \
		gffread>0:biology/gffread \
		ucsc-userapps>0:biology/ucsc-userapps

USES=		metaport python

.include <bsd.port.pre.mk>

# sra-tools is only supported on specific architectures
.if ${ARCH} == amd64 || ${ARCH} == aarch64
RUN_DEPENDS+=	sra-tools>0:biology/sra-tools
.endif

SUB_FILES=	biostar-shell pkg-message
PLIST_FILES=	bin/biostar-shell

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/biostar-shell ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
