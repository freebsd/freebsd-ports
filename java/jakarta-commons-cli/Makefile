# New ports collection makefile for:	Jakarta Commons CLI
# Date created:				November 14, 2002
# Whom:					Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	commons-cli
PORTVERSION=	1.0
PORTEPOCH=	1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	${PORTNAME:S,-,/,}/source
PKGNAMEPREFIX=	jakarta-
DISTNAME=	cli-${PORTVERSION}-src

MAINTAINER=	hq@FreeBSD.org
COMMENT=	Java library for command line arguments and options

BUILD_DEPENDS=	${JAVALIBDIR}/commons-lang.jar:${PORTSDIR}/java/jakarta-commons-lang

USE_JAVA=	yes
JAVA_VERSION=	1.2+

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_ANT=	yes
MAKE_ENV+=	ANT_INCLUDE_SHARED_JARS=YES
MAKE_ARGS=	-Dnoget=yes
ALL_TARGET=	jar
.if !defined(NOPORTDOCS)
ALL_TARGET+=	javadoc
.endif

JARFILE=	${PORTNAME}-${PORTVERSION}-beta-2-dev.jar
DESTJARFILE=	${PORTNAME}.jar
PLIST_FILES=	%%JAVAJARDIR%%/${DESTJARFILE}
.if !defined(NOPORTDOCS)
PORTDOCS=	apidocs LICENSE.txt
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/lib

do-install:
	@${ECHO_MSG} -n ">> Installing JAR as ${JAVAJARDIR}/${DESTJARFILE}..."
	@${INSTALL_DATA} ${WRKSRC}/target/${JARFILE} ${JAVAJARDIR}/${DESTJARFILE}
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/target/docs \
	  && ${FIND} apidocs -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} apidocs -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DOCSDIR}/
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
