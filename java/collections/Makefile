# New ports collection makefile for:    JDK1.1 Collections package
# Date created:		1999/08/08
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	collections
PORTVERSION=	1.1
CATEGORIES=	java devel
DISTNAME=	collections1_1
EXTRACT_SUFX=	.zip

MAINTAINER=	java@freebsd.org
COMMENT=	JDK1.2 Collections\' API for JDK1.1 environments

USE_JAVA=	yes
JAVA_VERSION=	1.1

USE_ZIP=	YES

WRKSRC=		${WRKDIR}/1.1collections
NO_BUILD=	yes
NO_CDROM=	"See the license"

.if !defined(NOPORTDOCS)
PORTDOCS=	LICENSE.TXT README.TXT javadoc
.endif
JARFILE=	collections.jar
PLIST_FILES+=	%%JAVAJARDIR%%/${JARFILE}

.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
DOWNLOAD_URL=	"http://javashoplm.sun.com/ECom/docs/Welcome.jsp?StoreId=22&PartDetailId=7264-collections-1.1-oth-JPR&SiteId=JSC&TransactionId=noreg"
IGNORE=	"You must manually fetch ${DISTNAME}${EXTRACT_SUFX} from ${DOWNLOAD_URL} and place it in ${DISTDIR} then run make again"
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${JARFILE}..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/lib/${JARFILE} ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/doc \
	  && ${FIND} ${PORTDOCS} -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} ${PORTDOCS} -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
