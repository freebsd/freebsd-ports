# New ports collection makefile for:	dnsjava
# Date created:				2004-11-19
# Whom:					Herve Quiroz <hq@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dnsjava
PORTVERSION=	2.0.6
PORTREVISION=	1
CATEGORIES=	dns java
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of DNS in Java

USE_JAVA=	yes
JAVA_VERSION=	1.6+

USE_ANT=	yes
ALL_TARGET=	jar
.if !defined(NOPORTDOCS)
ALL_TARGET+=	docs
.endif

SAMPLE_FILES=	examples.html USAGE dig.java jnamed.java lookup.java update.java
PLIST_FILES=	%%JAVAJARDIR%%/${PORTNAME}.jar ${SAMPLE_FILES:S,^,%%EXAMPLESDIR%%/,}
PLIST_DIRS=	%%EXAMPLESDIR%%
.if !defined(NOPORTDOCS)
OTHERDOCS=	README Changelog
PORTDOCS=	apidocs ${OTHERDOCS}
.endif

.include <bsd.port.pre.mk>

JDK_API!=	(${FIND} -s ${LOCALBASE}/share/doc/jdk1.? -maxdepth 1 -name api -type d 2>/dev/null || ${TRUE}) | ${TAIL} -n 1
.if ${JDK_API} != ""
MAKE_ARGS+=	-Dj2se.javadoc="${JDK_API}"
.endif

post-extract:
	@${RM} -rf ${WRKSRC}/doc
	@${MKDIR} ${WRKSRC}/doc

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${PORTNAME}.jar..."
	@${MKDIR} ${JAVAJARDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${PORTVERSION}.jar ${JAVAJARDIR}/${PORTNAME}.jar
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing samples in ${EXAMPLESDIR}/..."
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${SAMPLE_FILES:S,^,${WRKSRC}/,} ${EXAMPLESDIR}/
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}/..."
	@cd ${WRKSRC}/doc \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/apidocs/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} ${WRKSRC}/doc/{} ${DOCSDIR}/apidocs/{} \;
	@${INSTALL_DATA} ${OTHERDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
