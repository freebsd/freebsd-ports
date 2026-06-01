PORTNAME=	babashka
DISTVERSION=	1.12.218
CATEGORIES=	lang java linux
MASTER_SITES=	https://github.com/babashka/babashka/releases/download/v${DISTVERSION}/
DISTFILES_amd64=	babashka-${DISTVERSION}-linux-amd64-static.tar.gz
DISTFILES_aarch64=	babashka-${DISTVERSION}-linux-aarch64-static.tar.gz

MAINTAINER=	fox@FreeBSD.org
COMMENT=	Fast native Clojure scripting runtime
WWW=		https://babashka.org/

LICENSE=	EPL

ONLY_FOR_ARCHS=		aarch64 amd64
ONLY_FOR_ARCHS_REASON=	upstream only provides Linux binaries for amd64 and aarch64

USES=		linux:rl9
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
STRIP=

OPTIONS_DEFINE=	JAVA
OPTIONS_DEFAULT=	JAVA
JAVA_DESC=	Install OpenJDK for Clojure/Java interop
JAVA_USES=	java:run
JAVA_VARS=	JAVA_VERSION=17+ JAVA_OS=native JAVA_VENDOR=openjdk

PLIST_FILES=	bin/bb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bb ${STAGEDIR}${PREFIX}/bin/bb

.include <bsd.port.mk>
