PORTNAME=	bbmap
DISTVERSION=	39.34
CATEGORIES=	biology java
MASTER_SITES=	SF/bbmap/
DISTNAME=	BBMap_${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	BBMap short read aligner, and other bioinformatic tools
WWW=		https://jgi.doe.gov/data-and-tools/bbtools/ \
		https://sourceforge.net/projects/bbmap/ \
		https://bitbucket.org/berkeleylab/jgi-bbtools/src/master/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	bash:shells/bash \
		pbzip2:archivers/pbzip2 \
		pigz:archivers/pigz

USES=		java shebangfix

SHEBANG_FILES=	${WRKSRC}/*.sh

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

LIBEXEC_DIR=	${PREFIX}/libexec/bbmap

pre-configure:
	${REINPLACE_CMD} -e 's|"$$DIR""current/"|${JAVAJARDIR}/bbmap|g' \
		${WRKSRC}/*.sh
	${REINPLACE_CMD} \
		-e 's|"$$DIR""/calcmem.sh"|${LIBEXEC_DIR}/bbmap/calcmem.sh|g' \
		${WRKSRC}/*.sh

# FIXME: Find out which scripts are meant to be part of the CLI
do-install:
	@${MKDIR} ${STAGEDIR}${LIBEXEC_DIR}
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/bbmap
	${INSTALL_SCRIPT} ${WRKSRC}/*.sh ${STAGEDIR}${LIBEXEC_DIR}
	cd ${WRKSRC}/current && ${COPYTREE_SHARE} . \
		${STAGEDIR}${JAVAJARDIR}/bbmap
.for f in bbduk.sh bbnorm.sh dedupe.sh bbmap.sh bloomfilter.sh reformat.sh \
	bbmerge.sh tadpole.sh
	${RLN} ${STAGEDIR}${LIBEXEC_DIR}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
