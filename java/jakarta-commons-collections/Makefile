# New ports collection makefile for:	Jakarta Commons Collections
# Date created:				October 18, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	commons-collections
PORTVERSION=	3.0
CATEGORIES=	java
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	commons/collections/source/
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Classes that extend/augment the Java Collections Framework

BUILD_DEPENDS=	${ANT}:${PORTSDIR}/devel/apache-ant

USE_JAVA=	yes
JAVA_VERSION=	1.2+

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

ANT?=		${LOCALBASE}/bin/ant
ANT_TARGET=	jar
.if !defined(NOPORTDOCS)
ANT_TARGET+=	javadoc
OTHERDOCS=	DEVELOPERS-GUIDE.html LICENSE.txt PROPOSAL.html README.txt RELEASE-NOTES.html STATUS.html
PORTDOCS=	apidocs ${OTHERDOCS}
.endif
JARFILE=	${PORTNAME}-${PORTVERSION}.jar
DESTJARFILE=	${PORTNAME}.jar
PLIST_FILES+=	${JAVAJARDIR:S,^${PREFIX}/,,}/${DESTJARFILE}

do-build:
	@cd ${WRKSRC} && ${ANT} ${ANT_TARGET}

do-install:
	@${ECHO_CMD} -n ">> Installing JAR as ${JAVAJARDIR}/${DESTJARFILE}..."
	@${MKDIR} ${JAVAJARDIR}
	@${CP} ${WRKSRC}/build/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}
	@${ECHO_CMD} " [ DONE ]"

.if !defined(NOPORTDOCS)
	@${ECHO_CMD} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@${CP} -r ${WRKSRC}/build/docs/apidocs ${DOCSDIR}
	@${ECHO_CMD} -n " apidocs"
.for DOCFILE in ${OTHERDOCS}
	@${CP} ${WRKSRC}/${DOCFILE} ${DOCSDIR}
	@${ECHO_CMD} -n " ${DOCFILE}"
.endfor
	@${ECHO_CMD} " [ DONE ]"
.endif

.include <bsd.port.mk>
