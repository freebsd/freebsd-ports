# Created by: Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
# $FreeBSD$

PORTNAME=	pcgen
PORTVERSION=	5.16.4
CATEGORIES=	games java
MASTER_SITES=	SF/${PORTNAME}/PCGen%20Stable/${PORTVERSION}
DISTNAME=	pcgen${PORTVERSION:S/.//g}_full

MAINTAINER=	jsa@FreeBSD.org
COMMENT=	A Java-based RPG character generator and maintenance program

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USE_ZIP=	YES
WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION:S/.//g}
USE_JAVA=	YES
JAVA_VERSION=	1.6+
NO_BUILD=	YES

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
DATAFILES=	batch-convert.jar characters data filepaths.ini lib \
		logging.properties outputsheets pcgen.jar plugins preview system
PLIST_FILES+=	bin/pcgen

SUB_FILES=	pcgen.sh

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

NO_STAGE=	yes
do-install:
	@${ECHO_MSG} -n ">> Installing in ${DATADIR}..."
	@cd ${WRKSRC} && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${DATADIR}/{} ";"
	@cd ${WRKSRC} && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} "{}" ${DATADIR}/"{}" ";"
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing launcher script as ${PREFIX}/bin/pcgen..."
	@${INSTALL_SCRIPT} ${WRKDIR}/pcgen.sh ${PREFIX}/bin/pcgen
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd "${WRKSRC}/docs" && ${COPYTREE_SHARE} . "${DOCSDIR}"
	@${INSTALL_DATA} "${WRKSRC}"/*.html "${DOCSDIR}"
	@${ECHO_MSG} " [ DONE ]"
.endif

post-install:
	@${FIND} -s ${DATAFILES:S,^,${WRKSRC}/,} -not -type d 2>/dev/null | \
		${SED} -ne 's,^${WRKSRC},${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${DATAFILES:S,^,${WRKSRC}/,} -type d 2>/dev/null | \
		${SED} -ne 's,^${WRKSRC},@dirrm ${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S,^${PREFIX}/,,}' >> ${TMPPLIST}

.include <bsd.port.mk>
