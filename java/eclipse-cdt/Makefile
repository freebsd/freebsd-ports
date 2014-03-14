# Created by: gldisater@gldis.ca
# $FreeBSD$

PORTNAME=	${PLUGIN}
PORTVERSION=	6.0.2
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE}
MASTER_SITE_SUBDIR=tools/${PLUGIN}/releases/${ECLIPSE_CODENAME}/dist
PKGNAMEPREFIX=	eclipse-
DISTNAME=	${PLUGIN}-master-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C/C++ plugin for Eclipse IDE

RUN_DEPENDS=	eclipse:${PORTSDIR}/java/eclipse

USES=		zip
USE_JAVA=	YES
JAVA_OS=	native
JAVA_RUN=	YES
JAVA_VERSION=	1.6

NO_BUILD=	YES
NO_WRKSUBDIR=	YES

ECLIPSE_CODENAME=galileo
PLUGIN=		cdt
RM_VERSION=	5.1.0.201002161416
RM_NAME=	org.eclipse.cdt.core

RM_XLC=	features/org.eclipse.cdt.xlc.feature_6.0.0.201002161416.jar \
	features/org.eclipse.cdt.xlc.sdk_6.0.0.201002161416.jar \
	features/org.eclipse.cdt.xlc.source_6.0.0.201002161416.jar \
	plugins/org.eclipse.cdt.core.lrparser.xlc.source_5.1.0.201002161416.jar \
	plugins/org.eclipse.cdt.core.lrparser.xlc_5.1.0.201002161416.jar \
	plugins/org.eclipse.cdt.errorparsers.xlc.source_5.0.100.201002161416.jar \
	plugins/org.eclipse.cdt.errorparsers.xlc_5.0.100.201002161416.jar \
	plugins/org.eclipse.cdt.make.xlc.core.source_5.0.0.201002161416.jar \
	plugins/org.eclipse.cdt.make.xlc.core_5.0.0.201002161416.jar \
	plugins/org.eclipse.cdt.managedbuilder.xlc.core.source_5.0.0.201002161416.jar \
	plugins/org.eclipse.cdt.managedbuilder.xlc.core_5.0.0.201002161416.jar \
	plugins/org.eclipse.cdt.managedbuilder.xlc.ui.source_6.0.0.201002161416.jar \
	plugins/org.eclipse.cdt.managedbuilder.xlc.ui_6.0.0.201002161416.jar \
	plugins/org.eclipse.cdt.managedbuilder.xlupc.ui.source_1.0.0.201002161416.jar \
	plugins/org.eclipse.cdt.managedbuilder.xlupc.ui_1.0.0.201002161416.jar

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
RM_PLATFORM=	win32 solaris qnx macosx aix linux.ppc linux.ia64 linux.x86_64
PLIST_SUB+=	RM_I386=""
PLIST_SUB+=	RM_AMD64="@comment "
.endif
.if ${ARCH} == "amd64"
RM_PLATFORM=	win32 solaris qnx macosx aix linux.ppc linux.ia64 linux.x86
PLIST_SUB+=	RM_I386="@comment "
PLIST_SUB+=	RM_AMD64=""
.endif

do-patch:
# remove unneeded files
.for i in ${RM_PLATFORM}
	@${RM} ${WRKDIR}/plugins/${RM_NAME}.${i}.source_${RM_VERSION}.jar
	@${RM} ${WRKDIR}/plugins/${RM_NAME}.${i}_${RM_VERSION}.jar
.endfor
.for i in ${RM_XLC}
	@${RM} ${WRKDIR}/${i}
.endfor

do-install:
	@(cd ${WRKDIR} && ${COPYTREE_SHARE} "features plugins" ${STAGEDIR}${PREFIX}/lib/eclipse)

.include <bsd.port.post.mk>
