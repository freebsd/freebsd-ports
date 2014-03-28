# $FreeBSD$

PORTNAME=	pcgen
PORTVERSION=	6.02.1
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/PCGen%20Stable/${PORTVERSION}
DISTNAME=	pcgen${PORTVERSION:S/.//g}_full

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Java-based RPG character generator and maintenance program

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USES=		zip
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S/.//g}
USE_JAVA=	YES
JAVA_VERSION=	1.6+
NO_BUILD=	YES

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
DATAFILES=	batch-convert.jar characters data filepaths.ini lib \
		logging.properties outputsheets pcgen.jar plugins preview system

SUB_FILES=	pcgen.sh

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

PORTDOCS=	*

do-install:
	cd ${WRKSRC} && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${STAGEDIR}${DATADIR}/{} ";"
	cd ${WRKSRC} && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} "{}" ${STAGEDIR}${DATADIR}/"{}" ";"
	${INSTALL_SCRIPT} ${WRKDIR}/pcgen.sh ${STAGEDIR}${PREFIX}/bin/pcgen
.if ${PORT_OPTIONS:MDOCS}
	cd "${WRKSRC}/docs" && ${COPYTREE_SHARE} . "${STAGEDIR}${DOCSDIR}"
	${INSTALL_DATA} "${WRKSRC}"/*.html "${STAGEDIR}${DOCSDIR}"
.endif


.include <bsd.port.mk>
