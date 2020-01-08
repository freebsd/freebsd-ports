# Created by: Mauricio Herrera Cuadra <mauricio@arareko.net>
# $FreeBSD$

PORTNAME=	BioPerl-Run
PORTVERSION=	1.007003
CATEGORIES=	biology perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CJFIELDS
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Wrapper modules for common bioinformatics tools

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Algorithm-Diff>=0:devel/p5-Algorithm-Diff \
		p5-Bio-Cluster>=0:biology/p5-Bio-Cluster \
		p5-Bio-FeatureIO>=0:biology/p5-Bio-FeatureIO \
		p5-BioPerl>=1.007000:biology/p5-BioPerl \
		p5-Config-Any>=0:devel/p5-Config-Any \
		p5-File-Sort>=0:misc/p5-File-Sort \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-IPC-Run>=0:devel/p5-IPC-Run \
		p5-XML-Twig>=0:textproc/p5-XML-Twig

OPTIONS_DEFINE=	DOCS

USES=		perl5 shebangfix
USE_PERL5=	modbuild

NO_ARCH=	yes

SHEBANG_FILES=	scripts/*

post-install:
.for i in multi_hmmsearch panalysis papplmaker run_neighbor run_protdist
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/${i}.PLS ${STAGEDIR}${PREFIX}/bin/bp_${i}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS Changes INSTALL.PROGRAMS README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
