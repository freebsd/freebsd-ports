PORTNAME=	javamail
DISTVERSIONPREFIX=	${PORTNAME:tu}-
DISTVERSION=	1_6_2
PORTREVISION=	5
CATEGORIES=	java mail

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Reference Implementation of JSR 919
WWW=		https://javaee.github.io/javamail/

LICENSE=	GPLv2 CDDL
LICENSE_COMB=	dual

USES=		cpe java:ant
CPE_VENDOR=	sun
USE_GITHUB=	yes
GH_ACCOUNT=	javaee

NO_ARCH=	yes

PLIST_FILES=	%%JAVAJARDIR%%/mail.jar

PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET=	all docs
.endif

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION} != 8
_JAF_JAR=	${JAVALIBDIR}/activation.jar
BUILD_DEPENDS+=	${_JAF_JAR}:devel/javax-activation
RUN_DEPENDS+=	${_JAF_JAR}:devel/javax-activation
MAKE_ARGS+=	-Dactivation.jar=${_JAF_JAR}
.endif

do-install:
	@${ECHO_MSG} -n ">> Install JAR files in ${JAVAJARDIR}..."
	@${INSTALL_DATA} ${WRKSRC}/target/release/mail.jar ${STAGEDIR}${JAVAJARDIR}/
	@${ECHO_MSG} " [ DONE ]"
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/target/release && ${FIND} *.txt \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1
	@cd ${WRKSRC}/target/release/docs && ${FIND} *.txt javadocs \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO_MSG} -n ">> Installing samples in ${EXAMPLESDIR}..."
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/demo && ${FIND} src \
	  | ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${EXAMPLESDIR} > /dev/null 2>&1
	@${ECHO_MSG} " [ DONE ]"
.endif

.include <bsd.port.post.mk>
