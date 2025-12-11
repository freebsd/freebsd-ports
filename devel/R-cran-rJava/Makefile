PORTNAME=	rJava
DISTVERSION=	1.0-11
PORTREVISION=	1
CATEGORIES=	devel java
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	R to Java interface
WWW=		https://cran.r-project.org/package=rJava

LICENSE=	LGPL21

LIB_DEPENDS=	libicuuc.so:devel/icu	\
		libpcre2-8.so:devel/pcre2

USES=		cran:compiles java
# On JDK11+: checking whether JNI programs can be compiled... configure: error: Cannot compile a simple JNI program. See config.log for details.
JAVA_VERSION=	8

JRE_LIBS=	${JAVA_HOME}/jre/lib/${ARCH:S/armv6/arm/:S/armv7/arm/:S/powerpc/ppc/}/server	# JDK8
#JRE_LIBS=	${JAVA_HOME}/jre/lib/server	# JDK11
LDFLAGS=	"-Wl,-rpath=${JRE_LIBS} "
MAKE_ENV+=	JAVA_HOME=${JAVA_HOME}	\
		JAVA=${JAVA}	\
		JAVAC=${JAVA_HOME}/bin/javac \
		JAVAH=${JAVAH}	\
		JAR=${JAR}	\
		LD_LIBRARY_PATH="${JRE_LIBS}"	\
		JAVA_LD_LIBRARY_PATH="${JRE_LIBS}"	\
		JAVA_LIBS="-Wl,-rpath=${JRE_LIBS} -L${JRE_LIBS} -ljvm -lpthread"	\
		JAVA_CPPFLAGS="-I${JAVA_HOME}/jre/../include -I${JAVA_HOME}/jre/../include/${OPSYS:tl}"

#pre-configure:
	# Just for debug purpose but this fails with new USES=java although build is OK
#	${LOCALBASE}/bin/R CMD javareconf -e exit

.include <bsd.port.mk>
