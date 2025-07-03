PORTNAME=	icedtea-web
PORTVERSION=	1.8.8
DISTVERSIONPREFIX=	icedtea-web-
PORTREVISION=	27
CATEGORIES=	java www

MAINTAINER=	java@FreeBSD.org
COMMENT=	Free Java plug-in and Java Web Start for OpenJDK
WWW=		http://icedtea.classpath.org/wiki/IcedTea-Web

LICENSE=	GPLv2

BUILD_DEPENDS=	zip:archivers/zip \
		bash:shells/bash \
		gsed:textproc/gsed \
		${HAMCREST_JAR}:java/hamcrest \
		${JUNIT_JAR}:java/junit
RUN_DEPENDS=	bash:shells/bash

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		autoreconf compiler:c++11-lang desktop-file-utils gmake java \
		pkgconfig shebangfix xorg
JAVA_VERSION=	8
JAVA_OS=	native
JAVA_VENDOR=	openjdk
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	AdoptOpenJDK
GH_PROJECT=	IcedTea-Web
SHEBANG_FILES=	jrunscript.in shell-launcher/launchers.sh.in

CONFIGURE_ARGS=		--with-hamcrest="${HAMCREST_JAR}"
CONFIGURE_ARGS+=	--with-jdk-home="${JAVA_HOME}"
CONFIGURE_ARGS+=	--with-junit="${JUNIT_JAR}"
CONFIGURE_ARGS+=	--with-rhino="${RHINO_JAR}"
CONFIGURE_ARGS+=	--with-tagsoup="${TAGSOUP_JAR}"
CONFIGURE_ARGS+=	--with-itw-libs="DISTRIBUTION"
CONFIGURE_ARGS+=	--enable-shell-launchers
.for opt in asm chrome chromium ecj epiphany firefox jacoco midori opera
CONFIGURE_ARGS+=	--without-${opt}
.endfor
CONFIGURE_ENV=		BIN_BASH=${bash_CMD}
CONFIGURE_ENV+=		bashcompdir=${PREFIX}/etc/bash_completion.d
CONFIGURE_SHELL=	${bash_CMD}

TEST_TARGET=	check

# Upstream archive contains files with UTF-8 names
EXTRACT_CMD=	${SETENV} LC_ALL=en_US.UTF-8 /usr/bin/bsdtar

OPTIONS_DEFINE=	DOCS PLUGIN PLUGINJAR RHINO RUST TAGSOUP
OPTIONS_DEFAULT=PLUGINJAR RUST
OPTIONS_SUB=	yes

PLUGIN_DESC=	Enable the browser plug-in
PLUGINJAR_DESC=	Enable plugin.jar for itweb-javaws -html
RHINO_DESC=	Add support for Proxy Auto Config files
RUST_DESC=	Build modern launchers written in Rust
TAGSOUP_DESC=	Enable cleaning up of malformed JNLP files

DOCS_CONFIGURE_ENABLE=	docs
DOCS_PORTDOCS=		netx

RHINO_BUILD_DEPENDS=	${JAVASHAREDIR}/rhino/rhino.jar:lang/rhino
RHINO_RUN_DEPENDS=	${RHINO_BUILD_DEPENDS}
RHINO_VARS=		RHINO_JAR="${JAVASHAREDIR}/rhino/rhino.jar"
RHINO_VARS_OFF=		RHINO_JAR=no

RUST_BUILD_DEPENDS=	rustc:lang/${RUST_DEFAULT}

TAGSOUP_BUILD_DEPENDS=	${JAVALIBDIR}/tagsoup.jar:textproc/tagsoup
TAGSOUP_RUN_DEPENDS=	${TAGSOUP_BUILD_DEPENDS}
TAGSOUP_VARS=		TAGSOUP_JAR="${JAVALIBDIR}/tagsoup.jar"
TAGSOUP_VARS_OFF=	TAGSOUP_JAR=no

PLUGIN_CONFIGURE_ENABLE=native-plugin
PLUGIN_CONFIGURE_ENV=	MOZILLA_CFLAGS="-I${WRKDIR}/npapi-headers -DXP_UNIX" \
			MOZILLA_LIBS=" " # needs to be set and non-empty!
PLUGIN_DISTFILES=	libxul-npapi-headers-45.9.0${EXTRACT_SUFX}:npapi
PLUGIN_MASTER_SITES=	LOCAL/tobik:npapi
PLUGIN_TEST_TARGET=	plugin-tests
PLUGIN_USE=		GNOME=glib20
PLUGIN_USES=		webplugin:native gnome
PLUGIN_VARS=		WEBPLUGIN_DIR=${PREFIX}/lib \
			WEBPLUGIN_FILES=IcedTeaPlugin.so
PLUGIN_IMPLIES=	PLUGINJAR

PLUGINJAR_CONFIGURE_ENABLE=	pluginjar
PLUGINJAR_PORTDOCS=		plugin

HAMCREST_JAR=	${JAVALIBDIR}/hamcrest.jar
JUNIT_JAR=	${JAVALIBDIR}/junit.jar

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|^sed\([[:space:]]\)|gsed\1|' \
	    -e 's|\([[:space:]]\)sed\([[:space:]]\)|\1gsed\2|g' \
	    ${WRKSRC}/Makefile.am ${WRKSRC}/html-gen.sh
	${REINPLACE_CMD} -e 's|^Icon=javaws|Icon=itweb-javaws|' \
	    ${WRKSRC}/*.desktop.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/*.desktop ${STAGEDIR}${DESKTOPDIR}
.for lang in cs de en pl
.for man in javaws policyeditor
	${MV} ${STAGEDIR}${PREFIX}/share/man/${lang:Nen}/man1/${man}.1 \
	    ${STAGEDIR}${PREFIX}/share/man/${lang:Nen}/man1/itweb-${man}.1
.endfor
.endfor
	@${ECHO_MSG}
	@${ECHO_MSG} "Run \"make test\" to execute regression test."
	@${ECHO_MSG}

.include <bsd.port.post.mk>
