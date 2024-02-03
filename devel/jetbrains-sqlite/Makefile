PORTNAME=	sqlite
DISTVERSION=	233.14015.106
CATEGORIES=	devel
PKGNAMEPREFIX=	jetbrains-
DIST_SUBDIR=	jetbrains

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	IntelliJ SQLite native library
WWW=		https://github.com/JetBrains/intellij-community/tree/master/platform/sqlite

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../../LICENSE.txt

ONLY_FOR_ARCHS=	amd64 powerpc64le

BUILD_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	JetBrains
GH_PROJECT=	intellij-community
GH_TAGNAME=	1b8c945fe9801a1129e4bd03f6feda5ceae1804c

USE_JAVA=	yes
JAVA_VERSION=	17+
JAVA_BUILD=	yes

DATADIR=	${PREFIX}/share/jetbrains/${PORTNAME}
PLIST_FILES=	share/jetbrains/${PORTNAME}/${ARCH}/libsqliteij.so
WRKSRC_SUBDIR=	platform/sqlite

do-build:
	(cd ${WRKSRC} && \
		${SETENV} JAVA_HOME=${JAVA_HOME} OS=freebsd ARCH=${ARCH} ./make.sh)

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/${ARCH}
	${INSTALL_LIB} \
		${WRKSRC}/target/sqlite/freebsd-${ARCH}/libsqliteij.so \
		${STAGEDIR}${DATADIR}/${ARCH}

.include <bsd.port.mk>
