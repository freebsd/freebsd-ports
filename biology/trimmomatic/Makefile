# Created by: Dan Siercks <dsiercks@uwm.edu>
# $FreeBSD$

PORTNAME=	trimmomatic
DISTVERSION=	0.39
CATEGORIES=	biology java
MASTER_SITES=	http://www.usadellab.org/cms/uploads/supplementary/Trimmomatic/
DISTNAME=	Trimmomatic-${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Flexible read trimming tool for Illumina NGS data

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		zip
USE_JAVA=	yes

JAVA_RUN=	yes
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	trimmomatic

do-install:
	${INSTALL_DATA} ${WRKSRC}/trimmomatic-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/trimmomatic.jar
	cd ${WRKSRC} && ${COPYTREE_SHARE} adapters ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/trimmomatic ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
