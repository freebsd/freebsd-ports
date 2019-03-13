# $FreeBSD$

PORTNAME=	java-simple-serial-connector
PORTVERSION=	2.8.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	comms java

MAINTAINER=	kevans@FreeBSD.org
COMMENT=	Library for working with serial ports from Java

LICENSE=	LGPL3

USE_GITHUB=	yes
GH_ACCOUNT=	scream3r

MAJOR_MINOR=	${PORTVERSION:C/(.*)\.[0-9]*/\\1/}
USE_JAVA=	yes
USE_ANT=	yes
ALL_TARGET=	dist
CXXFLAGS+=	-I${JAVA_HOME}/include -I${JAVA_HOME}/include/freebsd
WRKSRC_LIBS=	${WRKSRC}/src/java/libs

PLIST_FILES=	${JAVA_HOME}/jre/lib/ext/jssc-${PORTVERSION}.jar

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64 || ${ARCH} == armv6 || ${ARCH} == armv7
JSSC_ARCH=		arm
.else
JSSC_ARCH=		${ARCH}
.endif

post-extract:
	@${CP} ${FILESDIR}/build.xml.in ${WRKSRC}/build.xml
	@${REINPLACE_CMD} -e 's|%%PORTVERSION%%|${PORTVERSION}|' ${WRKSRC}/build.xml

pre-build:
	${RM} -r ${WRKSRC_LIBS}/*
	${MKDIR} ${WRKSRC_LIBS}/freebsd
	(cd ${WRKSRC}/src/cpp/_nix_based && ${CXX} ${CXXFLAGS} ${CPPFLAGS} -shared -fPIC -o ${WRKSRC_LIBS}/freebsd/libjSSC-${MAJOR_MINOR}_${JSSC_ARCH}.so jssc.cpp)
	${STRIP_CMD} ${WRKSRC_LIBS}/freebsd/libjSSC-${MAJOR_MINOR}_${JSSC_ARCH}.so

do-install:
	@${MKDIR} ${STAGEDIR}${JAVA_HOME}/jre/lib/ext
	${CP} ${WRKSRC}/build/jssc-${PORTVERSION}.jar ${STAGEDIR}${JAVA_HOME}/jre/lib/ext

.include <bsd.port.post.mk>
