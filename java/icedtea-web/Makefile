# New ports collection makefile for: icedtea-web
# Date created:		July 11, 2011
# Whom:			Jung-uk Kim <jkim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icedtea-web
PORTVERSION=	1.1
CATEGORIES=	java www
MASTER_SITES=	http://icedtea.classpath.org/download/source/

MAINTAINER=	java@FreeBSD.org
COMMENT=	A free Java plug-in and Java Web Start for OpenJDK

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_JAVA=	1.6
JAVA_VENDOR=	openjdk
USE_XORG=	x11

OPTIONS=	PLUGIN "Enable the browser plug-in" on \
		RHINO "Add support for Proxy Auto Config files" off \
		TEST "Add support for running regression test" off

MAN1=		javaws.1
PLIST_FILES=	bin/itweb-settings bin/javaws \
		share/applications/itweb-settings.desktop \
		share/applications/javaws.desktop \
		share/pixmaps/javaws.png
PORTDATA=	about.jar about.jnlp netx.jar
PORTDOCS=	netx

BUILD_DEPENDS+=	${LOCALBASE}/bin/zip:${PORTSDIR}/archivers/zip \
		${LOCALBASE}/bin/pkg-config:${PORTSDIR}/devel/pkg-config \
		${LOCALBASE}/bin/ginstall:${PORTSDIR}/sysutils/coreutils

CONFIGURE_ARGS+=--with-ecj=no --with-jdk-home="${JAVA_HOME}"
CONFIGURE_ENV+=	INSTALL_DATA="${LOCALBASE}/bin/ginstall"

.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--disable-docs
.endif

.if defined(WITH_PLUGIN)
USE_WEBPLUGINS=	native
WEBPLUGINS_DIR=	${PREFIX}/lib
WEBPLUGINS_FILES=IcedTeaPlugin.so

PLIST_FILES+=	lib/IcedTeaPlugin.so
PORTDATA+=	plugin.jar
PORTDOCS+=	plugin

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/glib-2.0.pc:${PORTSDIR}/devel/glib20 \
		${LOCALBASE}/libdata/pkgconfig/gtk+-2.0.pc:${PORTSDIR}/x11-toolkits/gtk20 \
		${LOCALBASE}/libdata/pkgconfig/mozilla-plugin.pc:${PORTSDIR}/www/libxul

.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
.else
CONFIGURE_ARGS+=--disable-plugin
.endif

.if defined(WITH_RHINO)
CONFIGURE_ARGS+=--with-rhino=${JAVASHAREDIR}/rhino/rhino.jar
BUILD_DEPENDS+=	${JAVASHAREDIR}/rhino/rhino.jar:${PORTSDIR}/lang/rhino
RUN_DEPENDS+=	${JAVASHAREDIR}/rhino/rhino.jar:${PORTSDIR}/lang/rhino
.else
CONFIGURE_ARGS+=--with-rhino=no
.endif

.if defined(WITH_TEST)
CONFIGURE_ARGS+=--with-junit=${JAVALIBDIR}/junit.jar
BUILD_DEPENDS+=	${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit
.else
CONFIGURE_ARGS+=--with-junit=no
.endif

pre-extract:
	@${ECHO_MSG}
	@${ECHO_MSG} "IMPORTANT: To build IcedTea-Web ${PORTVERSION}, you have to turn on 'ICEDTEA' option"
	@${ECHO_MSG} "for java/openjdk6 (default).  Otherwise, it will neither build nor work."
	@${ECHO_MSG}
	@sleep 10

post-install:
	${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/itweb-settings.desktop \
	    ${WRKSRC}/javaws.desktop ${DESKTOPDIR}
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/javaws.png ${PREFIX}/share/pixmaps
.if defined(WITH_TEST)
	@${ECHO_MSG}
	@${ECHO_MSG} "Run \"make test\" to execute regression test."
	@${ECHO_MSG}

test:	install
	@(cd ${WRKSRC}; ${GMAKE} check)
.if defined(WITH_PLUGIN)
	@(cd ${WRKSRC}; ${GMAKE} plugin-tests)
.endif
.endif

.include <bsd.port.post.mk>
