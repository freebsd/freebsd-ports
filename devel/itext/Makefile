# ex:ts=8
# Ports collection makefile for:	itext
# Date created:			Apr 2, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	itext
PORTVERSION=	2.1.3
PORTEPOCH=	1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	iText-src-${PORTVERSION}

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	A Java-PDF Library

BUILD_DEPENDS=	${JAVAJARDIR}/bcmail.jar:${PORTSDIR}/java/bouncycastle
RUN_DEPENDS=	${JAVAJARDIR}/bcmail.jar:${PORTSDIR}/java/bouncycastle

WRKSRC=		${WRKDIR}/src
EXTRACT_AFTER_ARGS=	| (${MKDIR} ${WRKDIR} && ${TAR} -xf - -C ${WRKDIR})
USE_JAVA=	yes
JAVA_VERSION=	1.4+
USE_ANT=	yes
ALL_TARGET=	jar jar.rtf
MAKE_ENV=	ANT_INCLUDE_SHARED_JARS=YES
.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
PORTDOCS=	*
.endif

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar \
		%%JAVAJARDIR%%/${PORTNAME}-rtf.jar

do-install:
	@${INSTALL_DATA} ${WRKDIR}/lib/iText.jar \
		${JAVAJARDIR}/${PORTNAME}.jar
	@${INSTALL_DATA} ${WRKDIR}/lib/iText-rtf.jar \
		${JAVAJARDIR}/${PORTNAME}-rtf.jar
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/apidocs
	@${CP} -R ${WRKDIR}/build/docs/* ${DOCSDIR}/apidocs
	@${CHOWN} -h -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}/apidocs
.endif

.include <bsd.port.mk>
