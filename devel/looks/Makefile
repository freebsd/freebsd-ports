# New ports collection makefile for:	looks
# Date created:		22 May 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	looks
PORTVERSION=	2.0.2
CATEGORIES=	devel java
MASTER_SITES=	https://looks.dev.java.net/files/documents/31/${DISTREP}/
DISTNAME=	${PORTNAME}-${PORTVERSION:S|.|_|g}-${DISTDATE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The JGoodies Looks improve the appearance of your Java applications

FETCH_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

DISTDATE=	20060502
DISTREP=	31518

FETCH_CMD=	${LOCALBASE}/bin/wget
FETCH_BEFORE_ARGS=	--no-check-certificate
DISABLE_SIZE=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

JARFILE=	${PORTNAME}.jar

PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE}	\
		%%JAVAJARDIR%%/LICENSE.${PORTNAME}.txt
DOCFILES=	README.html RELEASE-NOTES.txt
EXAMPLES=	demo.jar lib/forms-1.0.6.jar tiny.jar
PORTDOCS=	*

.if !defined(NOPORTDOCS)
PLIST_FILES+=	${EXAMPLES:S|^|%%EXAMPLESDIR%%/|}
PLIST_DIRS+=	%%EXAMPLESDIR%%/lib %%EXAMPLESDIR%%
.endif

post-extract:
	@${MV} ${WRKSRC}/LICENSE.txt ${WRKSRC}/LICENSE.${PORTNAME}.txt

do-install:
	${INSTALL_DATA} ${JARFILE:S|.jar|-${PORTVERSION}.jar|:S|^|${WRKSRC}/|}	\
		${JAVAJARDIR}/${JARFILE}
	@${INSTALL_DATA} ${WRKSRC}/LICENSE.${PORTNAME}.txt ${JAVAJARDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}/lib
	@${INSTALL_DATA} ${DOCFILES:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${CP} -R ${WRKSRC}/docs/* ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/demo/|:S|lib|../lib|} ${EXAMPLESDIR}
	@${MV} ${EXAMPLESDIR}/forms-1.0.6.jar ${EXAMPLESDIR}/lib
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
