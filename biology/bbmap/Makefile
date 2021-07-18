PORTNAME=	bbmap
DISTVERSION=	38.90
CATEGORIES=	biology java
MASTER_SITES=	SF/bbmap/
DISTNAME=	BBMap_${PORTVERSION}

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	BBMap short read aligner, and other bioinformatic tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	bash:shells/bash \
		pigz:archivers/pigz \
		pbzip2:archivers/pbzip2

USES=		shebangfix
USE_JAVA=	yes

SHEBANG_FILES=	${WRKSRC}/*.sh

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

LIBEXEC_DIR=    ${PREFIX}/libexec/bbmap

pre-configure:
	${REINPLACE_CMD} -e 's|"$$DIR""current/"|${JAVAJARDIR}/bbmap|g' \
		${WRKSRC}/*.sh
	${REINPLACE_CMD} \
		-e 's|"$$DIR""/calcmem.sh"|${LIBEXEC_DIR}/bbmap/calcmem.sh|g' \
		${WRKSRC}/*.sh

do-install:
	@${MKDIR} ${STAGEDIR}${LIBEXEC_DIR}
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}/bbmap
	${INSTALL_SCRIPT} ${WRKSRC}/*.sh ${STAGEDIR}${LIBEXEC_DIR}
	cd ${WRKSRC}/current && ${COPYTREE_SHARE} . \
		${STAGEDIR}${JAVAJARDIR}/bbmap
.for f in bbduk.sh bbnorm.sh dedupe.sh bbmap.sh bloomfilter.sh reformat.sh
	${RLN} ${STAGEDIR}${LIBEXEC_DIR}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
