# Created by: Jose Marques
# $FreeBSD$

PORTNAME=	jaf
PORTVERSION=	1.1.1
CATEGORIES=	java devel
MASTER_SITES=	#
DISTNAME=	${PORTNAME}-${PORTVERSION:S,.,_,g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JavaBeansTM Activation Framework

USES=		zip
USE_JAVA=	YES
JAVA_VERSION=	1.6+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
NO_CDROM=	See the license
DOWNLOAD_URL=	http://www.oracle.com/technetwork/java/javasebusiness/downloads/java-archive-downloads-java-plat-419418.html\#jaf-1.1.1-fcs-oth-JPR

.if !defined(NOPORTDOCS)
DOCFILES1=	JAF-1.1.pdf JAF-1.1.ps JAF-1.1-changes.txt javadocs
DOCFILES2=	LICENSE.txt README.txt RELNOTES.txt
PORTDOCS=	${DOCFILES1} ${DOCFILES2}
.endif

PLIST_FILES=	%%JAVAJARDIR%%/activation.jar

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		you must manually fetch the distribution from ${DOWNLOAD_URL} and place it in ${DISTDIR} then run make again
.endif

do-install:
	@${ECHO_MSG} -n ">> Installing demo files in ${EXAMPLESDIR}..."
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC} && ${FIND} demo \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing JAR file as ${JAVAJARDIR}/activation.jar..."
	@${INSTALL_DATA} ${WRKSRC}/activation.jar ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${FIND} ${DOCFILES1} \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@cd ${WRKSRC} && ${FIND} ${DOCFILES2} \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif

post-install:
	@${FIND} -s ${WRKSRC}/demo -not -type d 2>/dev/null \
	  | ${SED} -ne 's,^${WRKSRC},${EXAMPLESDIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${WRKSRC}/demo -type d 2>/dev/null \
	  | ${SED} -ne 's,^${WRKSRC},@dirrm ${EXAMPLESDIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${EXAMPLESDIR:S,^${PREFIX}/,,}' >> ${TMPPLIST}

.include <bsd.port.post.mk>
