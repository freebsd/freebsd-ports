# $FreeBSD$

PORTNAME=	fastqc
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.5
CATEGORIES=	biology java perl5
MASTER_SITES=	https://www.bioinformatics.babraham.ac.uk/projects/fastqc/
DISTNAME=	${PORTNAME}_${DISTVERSIONPREFIX}${DISTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Quality control tool for high throughput sequence data

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

NO_ARCH=	yes
NO_BUILD=	yes

USES=		zip perl5 shebangfix
SHEBANG_FILES=	fastqc
USE_JAVA=	yes
USE_PERL5=	run

WRKSRC=		${WRKDIR}/FastQC

post-patch:
	${REINPLACE_CMD} \
		-e 's|$$RealBin$$delimiter|${DATADIR}$$delimiter${JAVAJARDIR}/fastqc$$delimiter|g' \
		-e 's|$$RealBin/|${JAVAJARDIR}/fastqc/|g' \
		${WRKSRC}/fastqc

# Help files are not optional docs, but required for Help menu functionality
do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}/fastqc
	${INSTALL_DATA} ${WRKSRC}/*.jar ${STAGEDIR}${JAVAJARDIR}/fastqc
	${INSTALL_SCRIPT} ${WRKSRC}/fastqc \
		${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} "Configuration Help Templates" \
		${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "net org uk" \
		${STAGEDIR}${JAVAJARDIR}/fastqc

.include <bsd.port.mk>
