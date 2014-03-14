# $FreeBSD$

PORTNAME=	jdk
PORTVERSION=	${JDK_VERSION}.${JDK_UPDATE_VER}
CATEGORIES=	java
MASTER_SITES=	#
DISTNAME=	jdk-${JDK_VERSION}u${JDK_UPDATE_VER}-apidocs
PKGNAMESUFFIX=	${JDK_VERSION}-doc

MAINTAINER=	java@FreeBSD.org
COMMENT=	Java Development Kit ${JDK_MAJOR_VER} Documentation

DOCSDIR?=	${PREFIX}/share/doc/jdk${JDK_VERSION}
NO_CDROM=	License does not allow distribution with fee.
RESTRICTED=	This documentation is under license and export control.
.if defined(NOPORTDOCS)
IGNORE=		port only installs documentation
.endif

WRKSRC=		${WRKDIR}/docs
JDK_VERSION=	7
JDK_UPDATE_VER=	45
DOWNLOAD_URL=	http://www.oracle.com/technetwork/java/javase/downloads/index.html

NO_BUILD=	yes
USES=		zip
PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=You must manually fetch ${DISTNAME}${EXTRACT_SUFX} from ${DOWNLOAD_URL} by selecting the "Download" link for the "Java SE 7 Documentation", place it in ${DISTDIR} and then run make again
.endif

do-install:
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} \* ${DOCSDIR}/)
	@${ECHO} " [ DONE ]"

.include <bsd.port.post.mk>
