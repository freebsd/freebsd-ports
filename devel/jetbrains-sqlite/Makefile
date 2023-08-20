PORTNAME=	sqlite
PORTVERSION=	232.8660.185
CATEGORIES=	devel
PKGNAMEPREFIX=	jetbrains-
DIST_SUBDIR=	jetbrains

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	IntelliJ SQLite native library
WWW=		https://github.com/JetBrains/intellij-community/tree/master/platform/sqlite

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=	amd64 powerpc64le

BUILD_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	JetBrains
GH_PROJECT=	intellij-community
GH_TAGNAME=	47fc12830b3814a57f15b1f21b379475bd437972

USE_JAVA=	yes
JAVA_VERSION=	17+
JAVA_BUILD=	yes

DATADIR=	${PREFIX}/share/jetbrains/${PORTNAME}
PLIST_FILES=	share/jetbrains/${PORTNAME}/${ARCH}/libsqliteij.so

do-build:
	(cd ${WRKSRC}/platform/sqlite && \
		${SETENV} JAVA_HOME=${JAVA_HOME} OS=freebsd ARCH=${ARCH} ./make.sh)

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/${ARCH}
	${INSTALL_LIB} \
		${WRKSRC}/platform/sqlite/target/sqlite/freebsd-${ARCH}/libsqliteij.so \
		${STAGEDIR}${DATADIR}/${ARCH}

.include <bsd.port.mk>
