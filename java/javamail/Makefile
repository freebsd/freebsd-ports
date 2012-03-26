# New ports collection makefile for:    JavaMail API Implementation
# Date created:		1999/08/08
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	javamail
PORTVERSION=	1.4.5
CATEGORIES=	java mail
MASTER_SITES=	http://kenai.com/downloads/javamail/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A Reference Implementation of JSR 919

BUILD_DEPENDS=	${JAVALIBDIR}/activation.jar:${PORTSDIR}/java/jaf
RUN_DEPENDS=	${JAVALIBDIR}/activation.jar:${PORTSDIR}/java/jaf

LICENSE=	GPLv2 CDDL
LICENSE_COMB=	dual

USE_ZIP=	YES
USE_JAVA=	YES
JAVA_VERSION=	1.5+
USE_ANT=	YES
MAKE_ENV=	ANT_INCLUDE_SHARED_JARS=YES

WRKSRC=		${WRKDIR}

.if !defined(NOPORTDOCS)
ALL_TARGET=	all docs
.endif

PLIST_FILES=	%%JAVAJARDIR%%/mail.jar

PORTDOCS=	*
PORTEXAMPLES=	*

do-install:
	@${ECHO_MSG} -n ">> Install JAR files in ${JAVAJARDIR}..."
	@${INSTALL_DATA} ${WRKSRC}/target/release/mail.jar ${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/target/release && ${FIND} *.txt \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@cd ${WRKSRC}/target/release/docs && ${FIND} *.txt javadocs \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif
.if !defined(NOPORTEXAMPLES)
	@${ECHO_MSG} -n ">> Installing samples in ${EXAMPLESDIR}..."
	@${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/demo && ${FIND} src \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.mk>
