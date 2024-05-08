PORTNAME=	sqlite
PORTVERSION=	241.15989.150
CATEGORIES=	devel
PKGNAMEPREFIX=	jetbrains-
DIST_SUBDIR=	jetbrains

MAINTAINER=	dmitry.wagin@ya.ru
COMMENT=	IntelliJ SQLite native library
WWW=		https://github.com/JetBrains/intellij-community/tree/master/platform/sqlite

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../../LICENSE.txt

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64le

BUILD_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	JetBrains
GH_PROJECT=	intellij-community
GH_TAGNAME=	814cdbbe79a503fcb7981988c8fe8ec070385e2a

USE_JAVA=	yes
JAVA_VERSION=	17+
JAVA_BUILD=	yes

DATADIR=	${PREFIX}/share/jetbrains/${PORTNAME}
WRKSRC_SUBDIR=	platform/sqlite
PLIST_FILES=	share/jetbrains/${PORTNAME}/${ARCH}/libsqliteij.so

do-build:
	(cd ${WRKSRC} && \
		${SETENV} JAVA_HOME=${JAVA_HOME} OS=freebsd ARCH=${ARCH} ./make.sh)

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/${ARCH}
	${INSTALL_LIB} \
		${WRKSRC}/target/sqlite/freebsd-${ARCH}/libsqliteij.so \
		${STAGEDIR}${DATADIR}/${ARCH}

.include <bsd.port.mk>
