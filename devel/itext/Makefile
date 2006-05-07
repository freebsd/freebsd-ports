# ex:ts=8
# Ports collection makefile for:	itext
# Date created:			Apr 2, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	itext
PORTVERSION=	1.4
PORTEPOCH=	1
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	stefan@FreeBSD.org
COMMENT=	A Java-PDF Library

WRKSRC=		${WRKDIR}/src
EXTRACT_AFTER_ARGS=	| (${MKDIR} ${WRKSRC} && ${TAR} -xf - -C ${WRKSRC})
USE_JAVA=	yes
JAVA_VERSION=	1.2+
USE_ANT=	yes
ALL_TARGET=	jar
.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
PORTDOCS=	*
.endif

PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar

do-install:
	@${INSTALL_DATA} ${WRKDIR}/build/bin/iText.jar \
		${JAVAJARDIR}/${PORTNAME}.jar
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/apidocs
	@${CP} -R ${WRKDIR}/build/docs/* ${DOCSDIR}/apidocs
	@${CHOWN} -h -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}/apidocs
.endif

.include <bsd.port.mk>
