# $FreeBSD$

PORTNAME=	jdk-doc
PORTVERSION=	${JDK_VERSION}.${JDK_UPDATE_VER}
CATEGORIES=	java
MASTER_SITES=	#
DISTNAME=	jdk-${JDK_VERSION}u${JDK_UPDATE_VER}-apidocs

MAINTAINER=	java@FreeBSD.org
COMMENT=	Java Development Kit ${JDK_MAJOR_VER} Documentation

LATEST_LINK=	jdk${JDK_VERSION}-doc
DOCSDIR?=	${PREFIX}/share/doc/jdk${JDK_VERSION}
NO_CDROM=	License does not allow distribution with fee.
RESTRICTED=	This documentation is under license and export control.
.if defined(NOPORTDOCS)
IGNORE=		port only installs documentation
.endif

WRKSRC=		${WRKDIR}/docs
JDK_VERSION=	7
JDK_UPDATE_VER=	25
DOWNLOAD_URL=	http://www.oracle.com/technetwork/java/javase/downloads/index.html

NO_BUILD=	yes
USE_ZIP=	yes
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=You must manually fetch ${DISTNAME}${EXTRACT_SUFX} from ${DOWNLOAD_URL} by selecting the \"Download\" link for the \"Java SE 7 Documentation\", place it in ${DISTDIR} and then run make again
.endif

do-install:
	@${ECHO} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} \* ${DOCSDIR}/)
	@${ECHO} " [ DONE ]"

.include <bsd.port.post.mk>
