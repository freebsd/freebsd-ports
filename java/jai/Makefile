# New ports collection makefile for:	JAI
# Date created:				2004-01-10
# Whom:					OISHI Masakuni <yamasa@bsdhouse.org>
#
# $FreeBSD$
#

PORTNAME=	jai
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	java graphics
MASTER_SITES=	#
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}-lib-linux-i586

MAINTAINER=	java@FreeBSD.org
COMMENT=	High performance image processing libraries for Java

USE_JAVA=	yes
JAVA_VERSION=	1.3+
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/./_/g}
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386

RESTRICTED=	"Redistribution is not permitted"

DOWNLOAD_URL=	http://java.sun.com/products/java-media/jai/downloads/download-${PORTVERSION:S/./_/g}.html

TARGET_DIR=	${JAVASHAREDIR}/${PORTNAME}
IMAGEIO_DIR=	${JAVASHAREDIR}/jai-imageio
PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///} JAVA_HOME=${JAVA_HOME:S/^${PREFIX}\///} IMAGEIO_DIR=${IMAGEIO_DIR:S/^${PREFIX}\///}
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE=		"You must manually fetch the \"Linux CLASSPATH Install\" distribution \(${DISTNAME}${EXTRACT_SUFX}\) from ${DOWNLOAD_URL}, place it in ${DISTDIR} and then run make again"
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
		@${INSTALL_DATA} ${WRKSRC}/COPYRIGHT-jai.txt ${TARGET_DIR}
		@${INSTALL_DATA} ${WRKSRC}/INSTALL-jai.txt ${TARGET_DIR}
		@${INSTALL_DATA} ${WRKSRC}/LICENSE-jai.txt ${TARGET_DIR}
		@${INSTALL_DATA} ${WRKSRC}/README-jai.txt ${TARGET_DIR}
		@${MKDIR} ${TARGET_DIR}/jar
		@${INSTALL_DATA} ${WRKSRC}/lib/jai_codec.jar ${TARGET_DIR}/jar
		@${INSTALL_DATA} ${WRKSRC}/lib/jai_core.jar ${TARGET_DIR}/jar
		@${INSTALL_DATA} ${WRKSRC}/lib/mlibwrapper_jai.jar ${TARGET_DIR}/jar
		@${MKDIR} ${TARGET_DIR}/lib
		@${INSTALL_DATA} ${WRKSRC}/lib/libmlib_jai.so ${TARGET_DIR}/lib
.if !defined(NOINSTALL_IN_JRE)
		@${LN} -sf ${TARGET_DIR}/jar/jai_codec.jar ${JAVA_HOME}/jre/lib/ext
		@${LN} -sf ${TARGET_DIR}/jar/jai_core.jar ${JAVA_HOME}/jre/lib/ext
		@${LN} -sf ${TARGET_DIR}/jar/mlibwrapper_jai.jar ${JAVA_HOME}/jre/lib/ext
		@${LN} -sf ${TARGET_DIR}/lib/libmlib_jai.so ${JAVA_HOME}/jre/lib/i386
.endif
		@${ECHO_MSG} " [DONE]"

post-install:
.if defined(NOINSTALL_IN_JRE) || defined(WITH_PLUGINWRAPPER)
		@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
