# $FreeBSD$

PORTNAME=	icedtea-web
PORTVERSION=	1.5
PORTREVISION=	1
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
USE_PERL5=	build
USE_XORG=	x11
USES=		desktop-file-utils gmake perl5 pkgconfig shebangfix
SHEBANG_FILES=	javac.in jrunscript.in launcher/launchers.in

WANT_GNOME=	yes

EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	| ${SETENV} LC_ALL=en_US.UTF-8 ${TAR} -xf -

PLIST_FILES=	bin/itweb-javaws \
		bin/itweb-policyeditor \
		bin/itweb-settings \
		man/man1/itweb-javaws.1.gz \
		man/man1/itweb-policyeditor.1.gz \
		man/man1/itweb-settings.1.gz \
		share/applications/itweb-javaws.desktop \
		share/applications/itweb-policyeditor.desktop \
		share/applications/itweb-settings.desktop \
		share/pixmaps/itweb-javaws.png
PORTDATA=	javaws_splash.png netx.jar
PORTDOCS=	netx

CONFIGURE_ARGS=	--with-asm=no --with-ecj=no --with-emma=no --with-jacoco=no
CONFIGURE_ARGS+=--with-jdk-home="${JAVA_HOME}"
CONFIGURE_ENV=	ac_cv_path_BIN_BASH=${bash_CMD}
SH=		${bash_CMD}

OPTIONS_DEFINE=	PLUGIN RHINO TEST
OPTIONS_DEFAULT=PLUGIN
PLUGIN_DESC=	Enable the browser plug-in
RHINO_DESC=	Add support for Proxy Auto Config files
TEST_DESC=	Add support for running regression test

DOCS_CONFIGURE_ENABLE=	docs
PLUGIN_CONFIGURE_ENABLE=plugin
RHINO_BUILD_DEPENDS=	${JAVASHAREDIR}/rhino/rhino.jar:${PORTSDIR}/lang/rhino
RHINO_RUN_DEPENDS=	${JAVASHAREDIR}/rhino/rhino.jar:${PORTSDIR}/lang/rhino
RHINO_CONFIGURE_OFF=	--with-rhino=no
RHINO_CONFIGURE_ON=	--with-rhino=${JAVASHAREDIR}/rhino/rhino.jar
TEST_BUILD_DEPENDS=	${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit
TEST_CONFIGURE_OFF=	--with-junit=no
TEST_CONFIGURE_ON=	--with-junit=${JAVALIBDIR}/junit.jar
PLUGIN_PLIST_FILES=	lib/IcedTeaPlugin.so
PLUGIN_USE=		GNOME=glib20
PLUGIN_USES=		gecko webplugin:native

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPLUGIN}
PORTDATA+=	plugin.jar
PORTDOCS+=	plugin
WEBPLUGIN_DIR=	${PREFIX}/lib
WEBPLUGIN_FILES=IcedTeaPlugin.so
.endif

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION} == "1.8.0"
EXTRA_PATCHES=	${PATCHDIR}/extrapatch-jdk8
.elif ${JAVA_PORT_VERSION} == "1.6.0"
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
	${CP} -fp ${FILESDIR}/*.html \
	    ${WRKSRC}/netx/net/sourceforge/jnlp/resources

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
	@(cd ${WRKSRC}; ${MAKE_CMD} check)
.if ${PORT_OPTIONS:MPLUGIN}
	@(cd ${WRKSRC}; ${MAKE_CMD} plugin-tests)
.endif
.endif

.include <bsd.port.post.mk>
