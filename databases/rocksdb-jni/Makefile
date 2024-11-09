PORTNAME=	rocksdb-jni
DISTVERSIONPREFIX=	v
DISTVERSION=	9.6.1
PORTREVISION=	1
CATEGORIES=	databases java
MASTER_SITES=	https://rocksdb-deps.s3-us-west-2.amazonaws.com/jars/:deps
DISTFILES=	assertj-core-2.9.0.jar:deps \
		cglib-3.3.0.jar:deps \
		hamcrest-2.2.jar:deps \
		junit-4.13.1.jar:deps \
		mockito-all-1.10.19.jar:deps
EXTRACT_ONLY=	${GH_ACCOUNT}-${GH_PROJECT}-${DISTVERSIONFULL}_GH0${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Java (JNI) interface to RocksDB
WWW=		https://rocksdb.org/ \
		https://github.com/facebook/rocksdb

LICENSE=	APACHE20 GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/../LICENSE.Apache
LICENSE_FILE_GPLv2=	${WRKSRC}/../COPYING

BUILD_DEPENDS=	googletest>0:devel/googletest
LIB_DEPENDS=	librocksdb.so:databases/rocksdb # librocksdbjni.so in the rocksdb.jar file is linked to librocksdb.so

USES=		cmake compiler:c++17-lang localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	facebook
GH_PROJECT=	rocksdb

USE_JAVA=	yes
JAVA_BUILD=	yes
JAVA_RUN=	yes
JAVA_VERSION=	21

WRKSRC_SUBDIR=	java

CMAKE_ARGS=	-DCMAKE_PROJECT_VERSION=${DISTVERSION} \
		-DJAVA_INCLUDE_PATH=${JAVA_HOME}/include

CXXFLAGS+=	-I${WRKSRC}/.. \
		-DOS_FREEBSD \
		-DROCKSDB_PLATFORM_POSIX
LDFLAGS+=	-lrocksdb

#MAKE_ENV+=	JAVA_HOME=${JAVA_HOME}
BINARY_ALIAS=	java=${JAVA_HOME}/bin/java

PLIST_FILES=	${JAVAJARDIR}/rocksdb-${PORTVERSION}.jar \
		${JAVAJARDIR}/rocksdbjni-${PORTVERSION}-javadoc.jar \
		${JAVAJARDIR}/rocksdbjni-${PORTVERSION}-sources.jar \
		${JAVAJARDIR}/rocksdbjni_classes.jar \
		${JAVAJARDIR}/rocksdbjni_test_classes.jar

post-extract:
	@${MKDIR} ${WRKSRC}/test-libs && \
		${RLN} ${DISTDIR}/assertj-core-2.9.0.jar ${WRKSRC}/test-libs && \
		${RLN} ${DISTDIR}/cglib-3.3.0.jar ${WRKSRC}/test-libs && \
		${RLN} ${DISTDIR}/hamcrest-2.2.jar ${WRKSRC}/test-libs && \
		${RLN} ${DISTDIR}/junit-4.13.1.jar ${WRKSRC}/test-libs && \
		${RLN} ${DISTDIR}/mockito-all-1.10.19.jar ${WRKSRC}/test-libs

do-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/rocksdb-${PORTVERSION}.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/rocksdbjni-${PORTVERSION}-sources.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/rocksdbjni-${PORTVERSION}-javadoc.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/rocksdbjni_classes.jar ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/rocksdbjni_test_classes.jar ${STAGEDIR}${JAVAJARDIR}

.include <bsd.port.mk>
