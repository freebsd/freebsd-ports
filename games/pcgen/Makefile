# Ports collection makefile for:	PCGen
# Date created:				17 November 2003
# Whom:					Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$

PORTNAME=	pcgen
PORTVERSION=	5.6.0
CATEGORIES=	games java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pcgen
DISTFILES=	pcgen${PORTVERSION:S/.//g}_partial.zip \
		skin.zip

MAINTAINER=	herve.quiroz@esil.univ-mrs.fr
COMMENT=	A Java-based RPG character generator and maintenance program

USE_ZIP=	YES
USE_JAVA=	YES
JAVA_VERSION=	1.4+
NO_BUILD=	YES

WRKSRC=		${WRKDIR}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
WRKDIRS=	characters data lib outputsheets system
WRKDOCSDIR=	${WRKSRC}/docs
WRKSCRIPT=	${WRKSRC}/pcgen.bsd.sh
PLIST_FILES+=	${DATADIR:S,^${PREFIX}/,,}/filepaths.ini
PLIST_DIRS+=	${DATADIR:S,^${PREFIX}/,,}

.if !defined(NOPORTDOCS)
PORTDOCS=	acknowledgments faqpages gmgen greetings.html index.html \
		images installationpages listfilepages menupages navlistindex.html \
		navtokenindex.html navtree navtree.html outputsheetpages \
		pcgen.css systemimages tabpages walkthroughpages
.endif

post-extract:
	${RM} -rf ${WRKSRC}/lib/themes/CVS
	${RM} -rf ${WRKSRC}/lib/CVS

do-install:
	@${ECHO_MSG} -n ">> Installing in ${DATADIR}..."
.for SOMEDIR in ${WRKDIRS}
	@cd ${WRKSRC} && ${FIND} ${SOMEDIR} -type d -exec ${MKDIR} ${DATADIR}/{} ";"
	@cd ${WRKSRC} && ${FIND} ${SOMEDIR} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} ";"
	@${ECHO_MSG} -n " ${SOMEDIR}"
.endfor
	@cd ${WRKSRC} && ${INSTALL_DATA} pcgen.jar ${DATADIR}
	@${ECHO_MSG} -n " pcgen.jar"
	@cd ${WRKSRC} && ${SED} "s|^java|${JAVA}|" pcgen.sh | ${SED} 's|`dirname $$0`|${DATADIR}|' > ${WRKSCRIPT}
	@cd ${WRKSRC} && ${INSTALL_SCRIPT} ${WRKSCRIPT} ${DATADIR}/pcgen.sh
	@${LN} -fs ${DATADIR}/pcgen.sh ${PREFIX}/bin/pcgen.sh
	@${ECHO_MSG} -n " pcgen.sh"
	@${ECHO_MSG} " [DONE]"
	@${ECHO_MSG} -n ">> Configuring..."
	@${ECHO_MSG} "pcgen.filepaths=user" > ${DATADIR}/filepaths.ini
	@${ECHO_MSG} " [DONE]"

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKDOCSDIR} && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} ";"
	@cd ${WRKDOCSDIR} && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} ";"
	@${ECHO_MSG} " [DONE]"
.endif

.include <bsd.port.mk>
