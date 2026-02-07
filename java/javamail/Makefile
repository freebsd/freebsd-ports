PORTNAME=	javamail
DISTVERSIONPREFIX=	${PORTNAME:tu}-
DISTVERSION=	1_6_2
PORTREVISION=	2
CATEGORIES=	java mail
MASTER_SITES=	https://github.com/jakartaee/jaf-api/releases/download/1.2.1/:jaf
DISTFILES=	jakarta.activation.jar:jaf
EXTRACT_ONLY=	javaee-javamail-JAVAMAIL-1_6_2_GH0.tar.gz

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Reference Implementation of JSR 919
WWW=		https://javaee.github.io/javamail/

LICENSE=	GPLv2 CDDL
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		cpe java:ant
USE_GITHUB=	yes
GH_ACCOUNT=	javaee
CPE_VENDOR=	sun

NO_ARCH=	yes

PLIST_FILES=	%%JAVAJARDIR%%/mail.jar

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET=	all docs
.endif

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION} != 8
PLIST_FILES+=	%%JAVAJARDIR%%/jakarta.activation.jar
MAKE_ARGS+=	-Dactivation.jar=${DISTDIR}/jakarta.activation.jar
.endif

do-install:
	@${ECHO_MSG} -n ">> Install JAR files in ${JAVAJARDIR}..."
	@${INSTALL_DATA} ${WRKSRC}/target/release/mail.jar ${STAGEDIR}${JAVAJARDIR}/
.if ${JAVA_PORT_VERSION} != 8
	@${INSTALL_DATA} ${DISTDIR}/jakarta.activation.jar ${STAGEDIR}${JAVAJARDIR}/
.endif
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
