# New ports collection makefile for:	eclipse-cdt
# Date created:				March 1, 2004
# Whom:					gldisater@gldis.ca
#
# $FreeBSD$
#

PORTNAME=	cdt
PORTVERSION=	3.1.2
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE}
MASTER_SITE_SUBDIR=tools/cdt/releases/callisto/dist/${PORTVERSION}
PKGNAMEPREFIX=	eclipse-
DISTNAME=	org.eclipse.cdt.sdk-${PORTVERSION}-linux.x86
DIST_SUBDIR=	eclipse

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	C/C++ IDE for Eclipse

RUN_DEPENDS=	${LOCALBASE}/eclipse:${PORTSDIR}/java/eclipse
PATCH_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_WRKSUBDIR=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native
USE_GMAKE=	yes
PORTVERSION_TS=	${PORTVERSION}.200702150621

.include <bsd.port.pre.mk>

ECLIPSE_OS=	freebsd
.if (${ARCH} == "amd64")
ECLIPSE_ARCH=	amd64
.else
ECLIPSE_ARCH=	x86
PLIST_FILES+=	eclipse/plugins/org.eclipse.cdt.core.freebsd.x86_${PORTVERSION_TS}/os/freebsd/x86/libpty.so \
		eclipse/plugins/org.eclipse.cdt.core.freebsd.x86_${PORTVERSION_TS}/os/freebsd/x86/libspawner.so
.endif

SCRIPTS_ENV=	PORTVERSION_TS=${PORTVERSION_TS} UNZIP_CMD=${UNZIP_CMD}

MAKE_ENV+=	ECLIPSE_ARCH=${ECLIPSE_ARCH} \
		ECLIPSE_OS=${ECLIPSE_OS} \
		PORTVERSION=${PORTVERSION} \
		PORTVERSION_TS=${PORTVERSION_TS} \
		JAVA_HOME=${JAVA_HOME}
PLIST_SUB+=	PORTVERSION_TS=${PORTVERSION_TS}

CDT_DIRS=	eclipse/features/org.eclipse.cdt_${PORTVERSION_TS} \
		eclipse/plugins/org.eclipse.cdt.core.freebsd.x86_${PORTVERSION_TS} \
		eclipse/plugins/org.eclipse.cdt.core.freebsd_${PORTVERSION_TS} \
		eclipse/plugins/org.eclipse.cdt.core_${PORTVERSION_TS} \
		eclipse/plugins/org.eclipse.cdt.managedbuilder.gnu.ui_${PORTVERSION_TS} \
		eclipse/plugins/org.eclipse.cdt.source.freebsd.gtk.x86_${PORTVERSION_TS} \
		eclipse/plugins/org.eclipse.cdt.source.linux.gtk.x86_${PORTVERSION_TS} \
		eclipse/plugins/org.eclipse.cdt.source_${PORTVERSION_TS}

CDT_JARS=	eclipse/plugins/org.eclipse.cdt.core_${PORTVERSION_TS}.jar \
		eclipse/plugins/org.eclipse.cdt.debug.core_${PORTVERSION_TS}.jar \
		eclipse/plugins/org.eclipse.cdt.debug.mi.core_${PORTVERSION_TS}.jar \
		eclipse/plugins/org.eclipse.cdt.debug.mi.ui_${PORTVERSION_TS}.jar \
		eclipse/plugins/org.eclipse.cdt.debug.ui_${PORTVERSION_TS}.jar \
		eclipse/plugins/org.eclipse.cdt.doc.isv_${PORTVERSION_TS}.jar \
		eclipse/plugins/org.eclipse.cdt.doc.user_${PORTVERSION_TS}.jar \
		eclipse/plugins/org.eclipse.cdt.launch_${PORTVERSION_TS}.jar \
		eclipse/plugins/org.eclipse.cdt.make.core_${PORTVERSION_TS}.jar \
		eclipse/plugins/org.eclipse.cdt.make.ui_${PORTVERSION_TS}.jar \
		eclipse/plugins/org.eclipse.cdt.managedbuilder.core_${PORTVERSION_TS}.jar \
		eclipse/plugins/org.eclipse.cdt.managedbuilder.gnu.ui_${PORTVERSION_TS}.jar \
		eclipse/plugins/org.eclipse.cdt.managedbuilder.ui_${PORTVERSION_TS}.jar \
		eclipse/plugins/org.eclipse.cdt.refactoring_${PORTVERSION_TS}.jar \
		eclipse/plugins/org.eclipse.cdt.sdk_${PORTVERSION_TS}.jar \
		eclipse/plugins/org.eclipse.cdt.ui_${PORTVERSION_TS}.jar \
		eclipse/plugins/org.eclipse.cdt_${PORTVERSION_TS}.jar

PLIST_FILES=	${CDT_JARS}

do-build:
		@${FIND} ${WRKSRC} -name \*.orig -delete
.if (${ARCH} == "i386")
		@(cd ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.source.freebsd.gtk.x86_${PORTVERSION_TS}/src/org.eclipse.cdt.core.freebsd_${PORTVERSION_TS}/library; \
		${SETENV} ${MAKE_ENV} ${GMAKE})
.endif

.if !defined(INSTALL_AS_USER)
pre-install:
		${SU_CMD} "${CHMOD} -R go-w ${WRKSRC}"
		${SU_CMD} "${CHOWN} -R 0:0 ${WRKSRC}"
.endif

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${MKDIR} ${PREFIX}/eclipse/features
		@${MKDIR} ${PREFIX}/eclipse/plugins
		cd ${WRKSRC} && ${INSTALL_DATA} ${CDT_JARS} ${PREFIX}/eclipse/plugins
		cd ${WRKSRC} && ${FIND} ${CDT_DIRS} \
			-type f -not -name '*.o' -print0 | ${XARGS} -0 ${TAR} -cf - | ( cd ${PREFIX} && ${TAR} -xf - )

post-install:
		cd ${WRKSRC} && ${FIND} -d ${CDT_DIRS} \
			-type f -not -name '*.o' -print >> ${TMPPLIST}
		cd ${WRKSRC} && ${FIND} -d ${CDT_DIRS} \
			-type d -not -name '*.o' -print0 | ${XARGS} -0 printf '@dirrm %s\n' >> ${TMPPLIST}

.include <bsd.port.post.mk>
