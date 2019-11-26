# Created by: mi
# $FreeBSD$

PORTNAME=	jode
PORTVERSION=	1.1.1.1
PORTREVISION=	4
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/1.1.2-pre1
DISTNAME=	${PORTNAME}-${VENDOR_VERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Java package containing a decompiler and an optimizer for Java

BUILD_DEPENDS=	${GETOPT_JAR}:java/java-getopt
RUN_DEPENDS:=	${BUILD_DEPENDS}

VENDOR_VERSION=	1.1.2-pre1
USE_JAVA=	yes
NEED_JAVAC=	yes
GNU_CONFIGURE=	yes
USES=		gmake perl5 shebangfix
SHEBANG_FILES=	${WRKSRC}/jcpp
USE_PERL5=	test
MAKE_JOBS_UNSAFE=	yes
TEST_TARGET=	check

GETOPT_JAR=	${JAVALIBDIR}/java-getopt.jar
CLASSLIB=	${JAVA_CLASSES}:${GETOPT_JAR}
CONFIGURE_ENV+=	CLASSLIB=${CLASSLIB} JAR="${JAR}" \
		JAVA="${JAVA}" JAVAC="${JAVAC}"
CONFIGURE_ARGS+=--datadir="${JAVALIBDIR}"
# Don't create the dependencies:
MAKE_ARGS+=	JAVADEP=:
SUB_LIST+=	GETOPT_JAR=${GETOPT_JAR}
SUB_FILES=	jode
PLIST_FILES=	bin/jode %%JAVAJARDIR%%/jode-${VENDOR_VERSION}.jar

post-patch:
	${FIND} ${WRKSRC} -name '*.java*' |	\
	    ${XARGS} ${GREP} --mmap -l 'Enumeration enum ' |	\
		${XARGS} ${REINPLACE_CMD} -E	\
			-e 's,enum([ \.]),enumeration\1,g'

post-build:
	cd ${WRKSRC} && ${JAR} cvf ${PORTNAME}-${VENDOR_VERSION}.jar \
		`${FIND} jode -name \*.class`

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-${VENDOR_VERSION}.jar \
		${STAGEDIR}/${JAVAJARDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/jode ${STAGEDIR}/${PREFIX}/bin/

.include <bsd.port.mk>
