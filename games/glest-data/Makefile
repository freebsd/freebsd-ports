# New ports collection makefile for:	glest-data
# Date created:				2006-04-10
# Whom:					Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	2.0.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	glest
PKGNAMEPREFIX=	glest-
DISTNAME=	glest_${PORTNAME}_2.0rc5
DIST_SUBDIR=	glest

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	Glest data files

USE_X_PREFIX=	yes
USE_ZIP=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/glest_game

DOCSDIR=	${PREFIX}/share/doc/glest
GLESTDIRE=	lib/glest
GLESTDATADIRE=	data maps screens techs tilesets
GLESTDOCSDIRE=	tech

PLIST_SUB=	GLESTDIRE=${GLESTDIRE}

post-extract:
	@${FIND} -E ${WRKDIR} -type f -iregex ".*\.(log|ini|html|txt|lng)" \
		-print0 | ${XARGS} -0 ${REINPLACE_CMD} -e 's/[[:cntrl:]]*$$//'

post-patch:
	@${FIND} -E ${WRKSRC} -type f -name '*.bak' -o -name '*.orig' | ${XARGS} ${RM}

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/${GLESTDOCSDIRE}
	${INSTALL_DATA} ${WRKSRC}/docs/license.txt ${DOCSDIR}/license-data.txt
	${INSTALL_DATA} ${WRKSRC}/docs/readme.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/${GLESTDOCSDIRE}/* ${DOCSDIR}/${GLESTDOCSDIRE}
.endif
	@${MKDIR} ${PREFIX}/${GLESTDIRE}
.for FILE in configuration.xml glest.ico glest.log glest.url
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/${GLESTDIRE}
.endfor
	@cd ${WRKSRC} && \
		${FIND} ${GLESTDATADIRE} -type d -exec ${MKDIR} "${PREFIX}/${GLESTDIRE}/{}" \; && \
		${FIND} ${GLESTDATADIRE} -type f -exec ${INSTALL_DATA} "{}" "${PREFIX}/${GLESTDIRE}/{}" \;

post-install:
	@${CHMOD} 666 ${PREFIX}/${GLESTDIRE}/glest.log

.include <bsd.port.mk>
