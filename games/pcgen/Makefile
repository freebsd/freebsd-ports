# Ports collection makefile for:	PCGen
# Date created:				17 November 2003
# Whom:					Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
#
# $FreeBSD$

PORTNAME=	pcgen
PORTVERSION=	5.5.7
CATEGORIES=	games java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pcgen
DISTFILES=	pcgen${PORTVERSION:S/.//g:S/0$//}_full.zip \
		skin.zip

MAINTAINER=	herve.quiroz@esil.univ-mrs.fr
COMMENT=	A Java-based RPG character generator and maintenance program

USE_ZIP=	YES
USE_JAVA=	1.4+
NO_BUILD=	YES

WRKSRC=		${WRKDIR}
PORTDESTDIR=	${JAVASHAREDIR}/${PORTNAME}
WRKDIRS=	characters data lib outputsheets plugins system
WRKDOCSDIR=	${WRKSRC}/docs
WRKSCRIPT=	${WRKSRC}/pcgen.bsd.sh
PLIST_SUB+=	T=${PORTDESTDIR:S/^${PREFIX}//}

.if !defined(NOPORTDOCS)
PORTDOCS=	acknowledgments faqpages gmgen greetings.html index.html \
		installationpages listfilepages menupages navlistindex.html \
		navtokenindex.html navtree navtree.html outputsheetpages \
		pcgen.css systemimages tabpages walkthroughpages
.endif

post-extract:
	${RM} -rf ${WRKSRC}/lib/themes/CVS
	${RM} -rf ${WRKSRC}/lib/CVS

do-install:
	@${ECHO_CMD} -n ">> Installing..."
	@cd ${WRKSRC} && ${FIND} ${WRKDIRS} -type d -exec ${MKDIR} ${PORTDESTDIR}/{} ";"
	@cd ${WRKSRC} && ${FIND} ${WRKDIRS} -type f -exec ${INSTALL_DATA} {} ${PORTDESTDIR}/{} ";"
	@cd ${WRKSRC} && ${INSTALL_DATA} pcgen.jar ${PORTDESTDIR}
	@cd ${WRKSRC} && ${SED} "s|^java|${JAVA}|" pcgen.sh | ${SED} 's|`dirname $$0`|${PORTDESTDIR}|' > ${WRKSCRIPT}
	@cd ${WRKSRC} && ${INSTALL_SCRIPT} ${WRKSCRIPT} ${PORTDESTDIR}/pcgen.sh
	@${LN} -fs ${PORTDESTDIR}/pcgen.sh ${PREFIX}/bin/pcgen.sh
	@${ECHO_CMD} " [DONE]"
	@${ECHO_CMD} -n ">> Configuring..."
	@${ECHO_CMD} "pcgen.filepaths=user" > ${PORTDESTDIR}/filepaths.ini
	@${ECHO_CMD} " [DONE]"

.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation..."
	@cd ${WRKDOCSDIR} && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} ";"
	@cd ${WRKDOCSDIR} && ${FIND} . -type f -exec ${INSTALL_MAN} {} ${DOCSDIR}/{} ";"
	@${ECHO_CMD} " [DONE]"
.endif

.include <bsd.port.mk>
