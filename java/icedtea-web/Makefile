# $FreeBSD$

PORTNAME=	icedtea-web
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	java www
MASTER_SITES=	http://icedtea.wildebeest.org/download/source/ \
		http://icedtea.classpath.org/download/source/

MAINTAINER=	java@FreeBSD.org
COMMENT=	Free Java plug-in and Java Web Start for OpenJDK

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/bin/zip:${PORTSDIR}/archivers/zip \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes
USE_JAVA=	yes
JAVA_OS=	native
JAVA_VENDOR=	openjdk
JAVA_VERSION=	1.6+
USE_PERL5=	build
USE_XORG=	x11
USES=		gmake perl5 pkgconfig shebangfix
SHEBANG_FILES=	javac.in jrunscript.in

WANT_GNOME=	yes

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	| ${SETENV} LC_ALL=en_US.UTF-8 ${TAR} -xf -

PLIST_FILES=	bin/itweb-javaws bin/itweb-settings \
		man/man1/itweb-javaws.1.gz \
		share/applications/itweb-javaws.desktop \
		share/applications/itweb-settings.desktop \
		share/pixmaps/itweb-javaws.png
PORTDATA=	about.jar about.jnlp javaws_splash.png netx.jar
PORTDOCS=	netx

CONFIGURE_ARGS=	--with-asm=no --with-ecj=no --with-emma=no --with-jacoco=no
CONFIGURE_ARGS+=--with-jdk-home="${JAVA_HOME}"
SH=		${bash_CMD}

OPTIONS_DEFINE=	PLUGIN RHINO TEST
OPTIONS_DEFAULT=PLUGIN
PLUGIN_DESC=	Enable the browser plug-in
RHINO_DESC=	Add support for Proxy Auto Config files
TEST_DESC=	Add support for running regression test

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDOCS)
CONFIGURE_ARGS+=--disable-docs
.endif

.if ${PORT_OPTIONS:MPLUGIN}
USE_GECKO=	libxul
USE_GNOME=	glib20
USES+=		webplugin:native
WEBPLUGIN_DIR=	${PREFIX}/lib
WEBPLUGIN_FILES=IcedTeaPlugin.so

PLIST_FILES+=	lib/IcedTeaPlugin.so
PORTDATA+=	plugin.jar
PORTDOCS+=	plugin
.else
CONFIGURE_ARGS+=--disable-plugin
.endif

.if ${PORT_OPTIONS:MRHINO}
BUILD_DEPENDS+=	${JAVASHAREDIR}/rhino/rhino.jar:${PORTSDIR}/lang/rhino
RUN_DEPENDS+=	${JAVASHAREDIR}/rhino/rhino.jar:${PORTSDIR}/lang/rhino
CONFIGURE_ARGS+=--with-rhino=${JAVASHAREDIR}/rhino/rhino.jar
.else
CONFIGURE_ARGS+=--with-rhino=no
.endif

.if ${PORT_OPTIONS:MTEST}
BUILD_DEPENDS+=	${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit
CONFIGURE_ARGS+=--with-junit=${JAVALIBDIR}/junit.jar
.else
CONFIGURE_ARGS+=--with-junit=no
.endif

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION} == "1.6.0"
pre-extract:
	@${ECHO_MSG}
	@${ECHO_MSG} "IMPORTANT: To build IcedTea-Web ${PORTVERSION}, you have to turn on 'ICEDTEA' option"
	@${ECHO_MSG} "for ${JAVA_PORT} (default).  Otherwise, it will neither build nor work."
	@${ECHO_MSG}
	@sleep 5
.endif

post-patch:
	${REINPLACE_CMD} -e 's|^Icon=javaws|Icon=itweb-javaws|' \
	    ${WRKSRC}/*.desktop.in
	${REINPLACE_CMD} -E 's|/bin/(ba)?sh|${bash_CMD}|' \
	    ${WRKSRC}/launcher/*.in \
	    ${WRKSRC}/plugin/tests/LiveConnect/build \
	    ${WRKSRC}/tests/netx/unit/net/sourceforge/jnlp/runtime/JNLPClassLoaderTest.java
	${REINPLACE_CMD} -e 's|%%JAR%%|${JAR}|' \
	    ${WRKSRC}/tests/netx/unit/net/sourceforge/jnlp/runtime/JNLPClassLoaderTest.java

.if ${PORT_OPTIONS:MTEST}
post-build:
	@${ECHO_MSG}
	@${ECHO_MSG} "Run \"make test\" to execute regression test."
	@${ECHO_MSG}
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/javaws.png \
	    ${STAGEDIR}${PREFIX}/share/pixmaps/itweb-javaws.png

.if ${PORT_OPTIONS:MTEST}
test:	build
	@(cd ${WRKSRC}; ${GMAKE} check)
.if ${PORT_OPTIONS:MPLUGIN}
	@(cd ${WRKSRC}; ${GMAKE} plugin-tests)
.endif
.endif

.include <bsd.port.post.mk>
