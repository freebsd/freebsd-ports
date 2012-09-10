# New ports collection makefile for: icedtea-web
# Date created:		July 11, 2011
# Whom:			Jung-uk Kim <jkim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icedtea-web
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	java www
MASTER_SITES=	http://icedtea.wildebeest.org/download/source/ \
		http://icedtea.classpath.org/download/source/

MAINTAINER=	java@FreeBSD.org
COMMENT=	A free Java plug-in and Java Web Start for OpenJDK

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_JAVA=	yes
JAVA_OS=	native
JAVA_VENDOR=	openjdk
JAVA_VERSION=	1.6+
USE_PERL5_BUILD=yes
USE_XORG=	x11

OPTIONS_DEFINE=	PLUGIN RHINO TEST
OPTIONS_DEFAULT=PLUGIN
PLUGIN_DESC=	Enable the browser plug-in
RHINO_DESC=	Add support for Proxy Auto Config files
TEST_DESC=	Add support for running regression test

.include <bsd.port.options.mk>

MAN1=		itweb-javaws.1
PLIST_FILES=	bin/itweb-javaws bin/itweb-settings \
		share/applications/itweb-javaws.desktop \
		share/applications/itweb-settings.desktop \
		share/pixmaps/itweb-javaws.png
PORTDATA=	about.jar about.jnlp netx.jar
PORTDOCS=	netx

BUILD_DEPENDS+=	${LOCALBASE}/bin/zip:${PORTSDIR}/archivers/zip
RUN_DEPENDS+=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

USE_PKGCONFIG=	yes

CONFIGURE_ARGS+=--with-ecj=no --with-jdk-home="${JAVA_HOME}"

EXTRACT_AFTER_ARGS=	| ${SETENV} LC_ALL=en_US.UTF-8 ${TAR} -xf -

.include <bsd.port.pre.mk>

.if empty(PORT_OPTIONS:MDOCS)
CONFIGURE_ARGS+=	--disable-docs
.endif

.if ${PORT_OPTIONS:MPLUGIN}
USE_WEBPLUGINS=	native
WEBPLUGINS_DIR=	${PREFIX}/lib
WEBPLUGINS_FILES=IcedTeaPlugin.so

PLIST_FILES+=	lib/IcedTeaPlugin.so
PORTDATA+=	plugin.jar
PORTDOCS+=	plugin

BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/glib-2.0.pc:${PORTSDIR}/devel/glib20 \
		${LOCALBASE}/libdata/pkgconfig/gtk+-2.0.pc:${PORTSDIR}/x11-toolkits/gtk20 \
		${LOCALBASE}/libdata/pkgconfig/mozilla-plugin.pc:${PORTSDIR}/www/libxul19

CONFIGURE_ARGS+=--with-gtk=2
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
.else
CONFIGURE_ARGS+=--disable-plugin
.endif

.if ${PORT_OPTIONS:MRHINO}
CONFIGURE_ARGS+=--with-rhino=${JAVASHAREDIR}/rhino/rhino.jar
BUILD_DEPENDS+=	${JAVASHAREDIR}/rhino/rhino.jar:${PORTSDIR}/lang/rhino
RUN_DEPENDS+=	${JAVASHAREDIR}/rhino/rhino.jar:${PORTSDIR}/lang/rhino
.else
CONFIGURE_ARGS+=--with-rhino=no
.endif

.if ${PORT_OPTIONS:MTEST}
CONFIGURE_ARGS+=--with-junit=${JAVALIBDIR}/junit.jar
BUILD_DEPENDS+=	${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash
.else
CONFIGURE_ARGS+=--with-junit=no
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/javac.in
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	    ${WRKSRC}/launcher/javaws.in

.if ${JAVA_PORT_VERSION} == "1.6.0"
pre-extract:
	@${ECHO_MSG}
	@${ECHO_MSG} "IMPORTANT: To build IcedTea-Web ${PORTVERSION}, you have to turn on 'ICEDTEA' option"
	@${ECHO_MSG} "for ${JAVA_PORT} (default).  Otherwise, it will neither build nor work."
	@${ECHO_MSG}
	@sleep 10
.endif

.if ${PORT_OPTIONS:MTEST}
post-build:
	@${ECHO_MSG}
	@${ECHO_MSG} "Run \"make test\" to execute regression test."
	@${ECHO_MSG}
.endif

post-install:
	${MKDIR} ${DESKTOPDIR}
	${REINPLACE_CMD} -e 's|^Icon=javaws|Icon=itweb-javaws|' \
	    ${WRKSRC}/itweb-javaws.desktop ${WRKSRC}/itweb-settings.desktop
	${INSTALL_DATA} ${WRKSRC}/itweb-javaws.desktop \
	    ${WRKSRC}/itweb-settings.desktop ${DESKTOPDIR}
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/javaws.png \
	    ${PREFIX}/share/pixmaps/itweb-javaws.png

.if ${PORT_OPTIONS:MTEST}
test:	build
	@${SED} -e 's|^SHELL = /bin/sh|SHELL = ${LOCALBASE}/bin/bash|' \
	    ${WRKSRC}/Makefile > ${WRKSRC}/Makefile.test
	@(cd ${WRKSRC}; ${GMAKE} -f Makefile.test check)
.if ${PORT_OPTIONS:MPLUGIN}
	@(cd ${WRKSRC}; ${GMAKE} -f Makefile.test plugin-tests)
.endif
.endif

.include <bsd.port.post.mk>
