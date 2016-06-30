# Created by: Mikhail T. <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	jxgrabkey
PORTVERSION=	0.3.2
CATEGORIES=	java devel
MASTER_SITES=	SF
DISTFILES=	${PORTNAME}-${PORTVERSION}_src${EXTRACT_SUFX}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	JNI library for easy use of global X11 hotkeys from Java

LICENSE=	LGPL3

USES=		tar:bz2
USE_JAVA=	yes
USE_ANT=	yes
OPTIONS_DEFINE=	TEST
TEST_BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:java/junit	\
			${JAVALIBDIR}/hamcrest.jar:java/hamcrest
MAKE_ENV+=	JAVA_HOME=${JAVA_HOME} OPSYS=${OPSYS}
PLIST_FILES=	%%JAVAJARDIR%%/JXGrabKey.jar lib/libJXGrabKey.so
USE_LDCONFIG=	yes

do-build:
	${SETENV} ${MAKE_ENV} ${MAKE} -C ${WRKSRC}/JXGrabKey/C++	\
		-f ${FILESDIR}/Makefile.JXGrabKey
	cd ${WRKSRC}/JXGrabKey/Java && ${ANT} -verbose jar

do-install:
	${INSTALL_LIB} ${WRKSRC}/JXGrabKey/C++/libJXGrabKey.so ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/JXGrabKey/Java/dist/JXGrabKey.jar ${STAGEDIR}${JAVAJARDIR}/

do-test-TEST-on: build
	${ECHO_MSG} Tests require a valid DISPLAY
	cd ${WRKSRC}/JXGrabKey/Java &&	\
		${SETENV} CLASSPATH=${JAVALIBDIR}/junit.jar:${JAVALIBDIR}/hamcrest.jar	\
		    LD_LIBRARY_PATH=${WRKSRC}/JXGrabKey/C++	\
			${ANT} -Djavac.classpath=${JAVALIBDIR}/junit.jar \
			    test

.include <bsd.port.mk>
