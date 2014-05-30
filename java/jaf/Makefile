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

PORTDOCS=	*
PORTEXAMPLES=	*

PLIST_FILES=	%%JAVAJARDIR%%/activation.jar

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		you must manually fetch the distribution from ${DOWNLOAD_URL} and place it in ${DISTDIR} then run make again
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/demo && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_DATA} ${WRKSRC}/activation.jar ${STAGEDIR}${JAVAJARDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} LICENSE.txt README.txt RELNOTES.txt \
		${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/docs && ${INSTALL_DATA} JAF-1.1.pdf JAF-1.1.ps \
		JAF-1.1-changes.txt ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} javadocs ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
