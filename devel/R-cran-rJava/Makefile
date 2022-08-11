PORTNAME=	rJava
DISTVERSION=	1.0-6
CATEGORIES=	devel java
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	R to Java interface

LICENSE=	LGPL21

LIB_DEPENDS=	libicuuc.so:devel/icu	\
		libpcre2-8.so:devel/pcre2

USES=		cran:compiles
USE_JAVA=	yes

JRE_LIBS=	${JAVA_HOME}/jre/lib/${ARCH:S/powerpc64/ppc64/}/server	# JDK8
#JRE_LIBS=	${JAVA_HOME}/jre/lib/server	# JDK11
LDFLAGS=	"-Wl,-rpath=${JRE_LIBS} "
MAKE_ENV=	JAVA_HOME=${JAVA_HOME}	\
		JAVA=${JAVA}	\
		JAVAC=${JAVAC}	\
		JAVAH=${JAVAH}	\
		JAR=${JAR}	\
		LD_LIBRARY_PATH="${JRE_LIBS}"	\
		JAVA_LD_LIBRARY_PATH="${JRE_LIBS}"	\
		JAVA_LIBS="-Wl,-rpath=${JRE_LIBS} -L${JRE_LIBS} -ljvm -lpthread"	\
		JAVA_CPPFLAGS="-I${JAVA_HOME}/jre/../include -I${JAVA_HOME}/jre/../include/${OPSYS:tl}"

pre-configure:
	# Just for debug purpose
	${LOCALBASE}/bin/R CMD javareconf -e exit

.include <bsd.port.mk>
