# Ports collection makefile for:	PCGen
# Date created:				17 November 2003
# Whom:					Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$

PORTNAME=	pcgen
PORTVERSION=	5.7.3
CATEGORIES=	games java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pcgen
DISTNAME=	pcgen${PORTVERSION:S/.//g}_partial

MAINTAINER=	hq@FreeBSD.org
COMMENT=	A Java-based RPG character generator and maintenance program

USE_ZIP=	YES
NO_WRKSUBDIR=	YES
USE_JAVA=	YES
JAVA_VERSION=	1.4+
NO_BUILD=	YES

DATADIR=	${JAVASHAREDIR}/${PORTNAME}
DATAFILES=	characters data filepaths.ini lib outputsheets pcgen.jar plugins system
PLIST_FILES+=	bin/pcgen.sh ${DATADIR:S,^${PREFIX}/,,}/pcgen.sh

.if !defined(NOPORTDOCS)
PORTDOCS=	acknowledgments faqpages gmgen greetings.html images \
		index.html installationpages listfilepages menupages \
		navlistindex.html navtokenindex.html navtree navtree.html \
		outputsheetpages pcgen.css tabpages walkthroughpages
.endif

post-extract:
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} -t ${RM} -rf

do-configure:
	@${ECHO_MSG} "pcgen.filepaths=user" > ${WRKSRC}/filepaths.ini
	@cd ${WRKSRC} && ${SED} "s|^java|${JAVA}|" pcgen.sh | ${SED} 's|`dirname $$0`|${DATADIR}|' > pcgen.sh.bsd

do-install:
	@${ECHO_MSG} -n ">> Installing in ${DATADIR}..."
	@cd ${WRKSRC} && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${DATADIR}/{} ";"
	@cd ${WRKSRC} && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} ";"
	@cd ${WRKSRC} && ${INSTALL_SCRIPT} pcgen.sh.bsd ${DATADIR}/pcgen.sh
	@${ECHO_MSG} " [ DONE ]"
	@${LN} -fs ${DATADIR}/pcgen.sh ${PREFIX}/bin/pcgen.sh
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/docs && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} ";"
	@cd ${WRKSRC}/docs && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} ";"
	@${ECHO_MSG} " [ DONE ]"
.endif

post-install:
	@${FIND} -s ${DATAFILES:S,^,${WRKSRC}/,} -not -type d 2>/dev/null | \
		${SED} -ne 's,^${WRKSRC},${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${DATAFILES:S,^,${WRKSRC}/,} -type d 2>/dev/null | \
		${SED} -ne 's,^${WRKSRC},@dirrm ${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S,^${PREFIX}/,,}' >> ${TMPPLIST}

.include <bsd.port.mk>
