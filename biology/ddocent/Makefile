# $FreeBSD$

PORTNAME=	dDocent
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.25
PORTREVISION=	1
CATEGORIES=	biology java

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Bash pipeline for RAD sequencing

LICENSE=	MIT

# ddocent test data do not unpack with FreeBSD 11.1 /usr/bin/unzip
RUN_DEPENDS=	unzip>=0:archivers/unzip \
		mawk>=0:lang/mawk \
		gawk>=0:lang/gawk \
		coreutils>=0:sysutils/coreutils \
		gnuplot>=0:math/gnuplot \
		parallel>=0:sysutils/parallel \
		bash:shells/bash \
		bwa>=0.7.13:biology/bwa \
		cd-hit>=0:biology/cd-hit \
		samtools>=1.3:biology/samtools \
		vcftools>=0.1.15:biology/vcftools \
		trimmomatic>=0:biology/trimmomatic \
		bamtools>=0:biology/bamtools \
		stacks>=0:biology/stacks \
		rainbow>=0:biology/rainbow \
		trimadap>=0:biology/trimadap \
		seqtk>=0:biology/seqtk \
		bedtools>=2.26.0:biology/bedtools \
		pear-merger>=0:biology/pear-merger \
		vcflib>=0:biology/vcflib \
		freebayes:biology/freebayes

USES=		perl5 python shebangfix
SHEBANG_FILES=	dDocent scripts/*.sh scripts/*.pl scripts/dDocent_filters
USE_JAVA=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	jpuritz

NO_BUILD=	yes
NO_ARCH=	yes

# These are on top of patch-dDocent, so don't apply them within the source
# tree, or they'll get picked up by patch generators, and hard-code PREFIX.
post-install:
	${REINPLACE_CMD} -i '' \
		-e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|g' \
		-e 's|%%BASH%%|${LOCALBASE}/bin/bash|g' \
		-e 's|python|${PYTHON_CMD}|g' \
		${STAGEDIR}${PREFIX}/bin/dDocent

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} \
		${WRKSRC}/dDocent \
		${WRKSRC}/*.sh \
		${FILESDIR}/ddocent-assembly-test \
		${FILESDIR}/ddocent-assembly-test-cleanup \
		${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/*.pl \
		${WRKSRC}/scripts/dDocent_filters \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
