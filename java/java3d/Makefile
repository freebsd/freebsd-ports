# New ports collection makefile for:	java3d
# Date created:				2003/12/19
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	java3d
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	java graphics
MASTER_SITES=	ftp://ftp.tux.org/pub/java/java3d/${PORTVERSION}/i386/fcs/ \
		ftp://metalab.unc.edu/pub/linux/devel/lang/java/blackdown.org/java3d/${PORTVERSION}/i386/fcs/
DISTNAME=	java3d-sdk-${PORTVERSION}-linux-i386
EXTRACT_SUFX=	.bin

MAINTAINER=	java@FreeBSD.org
COMMENT=	Blackdown Java3D Development Kit ${PORTVERSION} for Linux

EXTRACT_CMD=	${TAIL}
EXTRACT_BEFORE_ARGS=	+367
EXTRACT_AFTER_ARGS=	| ${BZIP2_CMD} -dc | ${TAR} xf -
USE_BZIP2=	yes

USE_JAVA=	1.3+
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386

NO_CDROM=	"License doesn\'t allow distribution"
NO_PACKAGE=	"License doesn\'t allow binary distributions"

TARGET_DIR=	${JAVASHAREDIR}/${PORTNAME}
PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///} JAVA_HOME=${JAVA_HOME:S/^${PREFIX}\///}
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if ${JAVA_OS} == "FreeBSD"
WITH_PLUGINWRAPPER=	yes
RUN_DEPENDS+=	${LOCALBASE}/lib/pluginwrapper/java3d.so:${PORTSDIR}/www/linuxpluginwrapper
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
		@${ECHO_CMD} -n ">> Creating destination directory..."
		@${MKDIR} ${TARGET_DIR}
		@${ECHO_CMD} " [DONE]"
		@${ECHO_CMD} -n ">> Installing libraries..."
		@${INSTALL_DATA} ${WRKSRC}/LICENSE-Java3D ${TARGET_DIR}
		@${INSTALL_DATA} ${WRKSRC}/README-Java3D ${TARGET_DIR}
		@${INSTALL_DATA} ${WRKSRC}/java3d-utils-src.jar ${TARGET_DIR}
		@${MKDIR} ${TARGET_DIR}/jar
		@${INSTALL_DATA} ${WRKSRC}/jre/lib/ext/* ${TARGET_DIR}/jar
		@${MKDIR} ${TARGET_DIR}/lib
		@${INSTALL_DATA} ${WRKSRC}/jre/lib/i386/* ${TARGET_DIR}/lib
.if !defined(NOINSTALL_IN_JRE)
		@${LN} -sf ${TARGET_DIR}/jar/* ${JAVA_HOME}/jre/lib/ext
		@${LN} -sf ${TARGET_DIR}/lib/* ${JAVA_HOME}/jre/lib/i386
.endif
		@${ECHO_CMD} " [DONE]"
.if !defined(NOPORTDOCS)
		@${ECHO_CMD} -n ">> Installing examples..."
		@${MKDIR} ${TARGET_DIR}/demo
		@${CP} -R ${WRKSRC}/demo/java3d/* ${TARGET_DIR}/demo
		@${ECHO_CMD} " [DONE]"
.endif

post-install:
.if defined(NOINSTALL_IN_JRE) || defined(WITH_PLUGINWRAPPER)
		@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
