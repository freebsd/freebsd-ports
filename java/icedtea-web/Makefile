# $FreeBSD$

PORTNAME=	icedtea-web
PORTVERSION=	1.6.2
CATEGORIES=	java www
MASTER_SITES=	http://icedtea.wildebeest.org/download/source/ \
		http://icedtea.classpath.org/download/source/

MAINTAINER=	java@FreeBSD.org
COMMENT=	Free Java plug-in and Java Web Start for OpenJDK

LICENSE=	GPLv2

BUILD_DEPENDS=	zip:archivers/zip \
		bash:shells/bash \
		gsed:textproc/gsed
RUN_DEPENDS=	bash:shells/bash
TEST_DEPENDS=	${HAMCREST_JAR}:java/hamcrest \
		${JUNIT_JAR}:java/junit

GNU_CONFIGURE=	yes
USE_JAVA=	yes
JAVA_OS=	native
JAVA_VENDOR=	openjdk
USE_PERL5=	build
USE_XORG=	x11
USES=		desktop-file-utils gmake perl5 pkgconfig shebangfix
SHEBANG_FILES=	jrunscript.in launcher/launchers.in

WANT_GNOME=	yes

CONFIGURE_ARGS=		--with-hamcrest="${HAMCREST_JAR}"
CONFIGURE_ARGS+=	--with-jdk-home="${JAVA_HOME}"
CONFIGURE_ARGS+=	--with-jre-home="${JAVA_HOME}/jre"
CONFIGURE_ARGS+=	--with-junit="${JUNIT_JAR}"
CONFIGURE_ARGS+=	--with-rhino="${RHINO_JAR}"
CONFIGURE_ARGS+=	--with-tagsoup="${TAGSOUP_JAR}"
.for opt in asm chrome chromium ecj epiphany firefox jacoco midori opera
CONFIGURE_ARGS+=	--without-${opt}
.endfor
CONFIGURE_ENV=		BIN_BASH=${bash_CMD}
CONFIGURE_SHELL=	${bash_CMD}

TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS PLUGIN RHINO TAGSOUP
OPTIONS_DEFAULT=PLUGIN
OPTIONS_SUB=	yes

PLUGIN_DESC=	Enable the browser plug-in
RHINO_DESC=	Add support for Proxy Auto Config files
TAGSOUP_DESC=	Enable cleaning up of malformed JNLP files

DOCS_CONFIGURE_ENABLE=	docs
DOCS_PORTDOCS=		netx

RHINO_BUILD_DEPENDS=	${JAVASHAREDIR}/rhino/rhino.jar:lang/rhino
RHINO_RUN_DEPENDS=	${RHINO_BUILD_DEPENDS}
RHINO_VARS=		RHINO_JAR="${JAVASHAREDIR}/rhino/rhino.jar"
RHINO_VARS_OFF=		RHINO_JAR=no

TAGSOUP_BUILD_DEPENDS=	${JAVALIBDIR}/tagsoup.jar:textproc/tagsoup
TAGSOUP_RUN_DEPENDS=	${TAGSOUP_BUILD_DEPENDS}
TAGSOUP_VARS=		TAGSOUP_JAR="${JAVALIBDIR}/tagsoup.jar"
TAGSOUP_VARS_OFF=	TAGSOUP_JAR=no

PLUGIN_CONFIGURE_ENABLE=plugin
PLUGIN_PORTDOCS=	plugin
PLUGIN_TEST_TARGET=	plugin-tests
PLUGIN_USE=		GNOME=glib20
PLUGIN_USES=		gecko webplugin:native
PLUGIN_VARS=		WEBPLUGIN_DIR=${PREFIX}/lib
PLUGIN_VARS+=		WEBPLUGIN_FILES=IcedTeaPlugin.so

HAMCREST_JAR=	${JAVALIBDIR}/hamcrest.jar
JUNIT_JAR=	${JAVALIBDIR}/junit.jar

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
	${REINPLACE_CMD} -e 's|^sed\([[:space:]]\)|gsed\1|' \
	    -e 's|\([[:space:]]\)sed\([[:space:]]\)|\1gsed\2|g' \
	    ${WRKSRC}/Makefile.in ${WRKSRC}/html-gen.sh
	${REINPLACE_CMD} -e 's|^Icon=javaws|Icon=itweb-javaws|' \
	    ${WRKSRC}/*.desktop.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/*.desktop ${STAGEDIR}${DESKTOPDIR}
.for lang in cs de en pl
.for man in javaws policyeditor
	${MV} ${STAGEDIR}${MANPREFIX}/man/${lang:Nen}/man1/${man}.1 \
	    ${STAGEDIR}${MANPREFIX}/man/${lang:Nen}/man1/itweb-${man}.1
.endfor
.endfor
	@${ECHO_MSG}
	@${ECHO_MSG} "Run \"make test\" to execute regression test."
	@${ECHO_MSG}

.include <bsd.port.post.mk>
