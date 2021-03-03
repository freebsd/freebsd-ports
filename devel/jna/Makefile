# $FreeBSD$

PORTNAME=	jna
PORTVERSION=	5.6.0
CATEGORIES=	devel java

MAINTAINER=	ports@markdixon.name
COMMENT=	Java access to native shared libraries

LICENSE=	LGPL21+ APACHE20
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_FILE_LGPL21+ =	${WRKSRC}/LGPL2.1
LICENSE_FILE_APACHE20=	${WRKSRC}/AL2.0

BROKEN_armv6=		fails to compile: build.xml: compilation failed
BROKEN_armv7=		fails to compile: build.xml: compilation failed

USES=		autoreconf:build gmake libtool xorg
USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION=	8+
USE_XORG=	x11 xt
MAKE_ARGS=	-DCC="${CC}" -DLD="${LD}"
MAKE_ENV=	ANT_OPTS=-Drelease -DARCH=${ANT_ARCH}

USE_GITHUB=	yes
GH_ACCOUNT=	java-native-access

PORTDOCS=	javadoc platform-${PORTVERSION}-javadoc.jar
PLIST_FILES=	%%JAVAJARDIR%%/jna-platform.jar \
		%%JAVAJARDIR%%/jna.jar

ALL_TARGET=	native jar
TEST_TARGET=	test

OPTIONS_DEFINE=	DOCS

ANT_ARCH=	${ARCH:S/amd64/x86-64/:S/i386/x86/:S/powerpc64/ppc64/}

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
USE_GCC=	any
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/native/Makefile

post-build-DOCS-on:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${ANT} javadoc

do-install:
	${INSTALL_DATA} ${WRKSRC}/build/freebsd-${ANT_ARCH}.jar \
		${STAGEDIR}${JAVAJARDIR}/jna-platform.jar
	${INSTALL_DATA} ${WRKSRC}/build/jna.jar \
		${STAGEDIR}${JAVAJARDIR}/jna.jar

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} javadoc ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/dist/platform-${PORTVERSION}-javadoc.jar \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
