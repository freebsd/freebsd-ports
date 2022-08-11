PORTNAME=	sigar
PORTVERSION=	1.7.3
PORTREVISION=	11
CATEGORIES=	java devel
PKGNAMEPREFIX=	java-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java bindings for the Sigar system information API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/NOTICE

BROKEN_armv6=		fails to compile: jni-build.xml: gcc failed with return code 1
BROKEN_armv7=		fails to compile: jni-build.xml: gcc failed with return code 1

BUILD_DEPENDS=	${ANT_CMD}:devel/apache-ant
LIB_DEPENDS=	libsigar.so:devel/sigar
TEST_DEPENDS=	${JAVALIBDIR}/junit.jar:java/junit

USE_GITHUB=	yes
GH_ACCOUNT=	polo-language # amishHammer
GH_TAGNAME=	6719d4d

USES=		perl5
USE_PERL5=	build
USE_JAVA=	yes
JAVA_RUN=	yes
NO_CCACHE=	yes

BUILD_WRKSRC=	${WRKSRC}/bindings/java

ANT_CMD?=	${LOCALBASE}/bin/ant
INVOKE_ANT=	${SETENV} PATH=${PATH}:${WRKSRC}/bin JAVA_HOME=${JAVA_HOME} \
		${ANT_CMD}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
LIBNAME=	libsigar-${ARCH:S,i386,x86,:S,powerpc64,ppc64,}-${OPSYS:tl}-1
.else
IGNORE=		${OPSYS} platform is not supported
.endif

PLIST_FILES=	${JAVAJARDIR}/${PORTNAME}.jar \
		${JAVAJARDIR}/${LIBNAME}.so

do-build:
	${MKDIR} ${WRKSRC}/bin
	${LN} -s `which ${CC}` ${WRKSRC}/bin/gcc
	@cd ${BUILD_WRKSRC} && ${INVOKE_ANT} build

do-test:
	@cd ${BUILD_WRKSRC} && ${INVOKE_ANT} \
		-Djunit.jar="${JAVALIBDIR}/junit.jar" test

do-install:
	${INSTALL_DATA} ${WRKSRC}/bindings/java/sigar-bin/lib/sigar.jar \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}.jar
	${INSTALL_LIB} ${WRKSRC}/bindings/java/sigar-bin/lib/${LIBNAME}.so \
		${STAGEDIR}${JAVAJARDIR}/${LIBNAME}.so

.include <bsd.port.post.mk>
