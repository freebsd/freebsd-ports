# New ports collection makefile for:	JAI Image I/O Tools
# Date created:				2004-01-10
# Whom:					OISHI Masakuni <yamasa@bsdhouse.org>
#
# $FreeBSD$
#

PORTNAME=	jai-imageio
PORTVERSION=	1.0
CATEGORIES=	java graphics
MASTER_SITES=	#
DISTNAME=	${PORTNAME:S/-/_/}-${PORTVERSION:S/./_/g}-lib-linux-i586

MAINTAINER=	java@FreeBSD.org
COMMENT=	Plug-ins for the Java Image I/O Framework

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386

RESTRICTED=	"Redistribution is not permitted"

DOWNLOAD_URL=	http://java.sun.com/products/java-media/jai/downloads/download-iio.html

TARGET_DIR=	${JAVASHAREDIR}/${PORTNAME}
PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///} JAVA_HOME=${JAVA_HOME:S/^${PREFIX}\///}
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=		"You must manually fetch the \"Linux Install\" distribution \(${DISTNAME}${EXTRACT_SUFX}\) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again"
.endif

.if ${JAVA_PORT_OS} == "native"
WITH_PLUGINWRAPPER=	yes
RUN_DEPENDS+=	${LOCALBASE}/lib/pluginwrapper/jai.so:${PORTSDIR}/www/linuxpluginwrapper
.endif

.if defined(NOINSTALL_IN_JRE)
PLIST_SUB+=	INSTALL_IN_JRE="@comment "
.else
PLIST_SUB+=	INSTALL_IN_JRE=""
.endif

pre-install:
.if defined(NOINSTALL_IN_JRE)
		@${SED} -e "s:%%TARGET_DIR%%:${TARGET_DIR}:g" ${MASTERDIR}/pkg-message-jre > ${PKGMESSAGE}
.endif
.if defined(WITH_PLUGINWRAPPER)
.if defined(NOINSTALL_IN_JRE)
		@${ECHO_CMD} >> ${PKGMESSAGE}
		@${SED} -e "s:%%LIBDIR%%:${TARGET_DIR}/lib:g" ${MASTERDIR}/pkg-message-libmap >> ${PKGMESSAGE}
.else
		@${SED} -e "s:%%LIBDIR%%:${JAVA_HOME}/jre/lib/i386:g" ${MASTERDIR}/pkg-message-libmap > ${PKGMESSAGE}
.endif
.endif

do-install:
		@${ECHO_MSG} -n ">> Creating destination directory..."
		@${MKDIR} ${TARGET_DIR}
		@${ECHO_MSG} " [DONE]"
		@${ECHO_MSG} -n ">> Installing libraries..."
		@${INSTALL_DATA} ${WRKSRC}/COPYRIGHT-jai_imageio.txt ${TARGET_DIR}
		@${INSTALL_DATA} ${WRKSRC}/LICENSE-jai_imageio.txt ${TARGET_DIR}
		@${INSTALL_DATA} ${WRKSRC}/README-jai_imageio.html ${TARGET_DIR}
		@${MKDIR} ${TARGET_DIR}/jar
		@${INSTALL_DATA} ${WRKSRC}/clibwrapper_jiio.jar ${TARGET_DIR}/jar
		@${INSTALL_DATA} ${WRKSRC}/jai_imageio.jar ${TARGET_DIR}/jar
		@${INSTALL_DATA} ${WRKSRC}/mlibwrapper_jai.jar ${TARGET_DIR}/jar
		@${MKDIR} ${TARGET_DIR}/lib
		@${INSTALL_DATA} ${WRKSRC}/libclib_jiio.so ${TARGET_DIR}/lib
.if !defined(NOINSTALL_IN_JRE)
		@${LN} -sf ${TARGET_DIR}/jar/clibwrapper_jiio.jar ${JAVA_HOME}/jre/lib/ext
		@${LN} -sf ${TARGET_DIR}/jar/jai_imageio.jar ${JAVA_HOME}/jre/lib/ext
		@${TEST} -e ${JAVA_HOME}/jre/lib/ext/mlibwrapper_jai.jar || ${LN} -sf ${TARGET_DIR}/jar/mlibwrapper_jai.jar ${JAVA_HOME}/jre/lib/ext
		@${LN} -sf ${TARGET_DIR}/lib/libclib_jiio.so ${JAVA_HOME}/jre/lib/i386
.endif
		@${ECHO_MSG} " [DONE]"

post-install:
.if defined(NOINSTALL_IN_JRE) || defined(WITH_PLUGINWRAPPER)
		@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
