# New ports collection makefile for:	eclipse-cdt
# Date created:				March 1, 2004
# Whom:					gldisater@gldis.ca
#
# $FreeBSD$
#

PORTNAME=	cdt
PORTVERSION=	3.0.2
CATEGORIES=	java devel
MASTER_SITES=	http://download.eclipse.org/tools/cdt/releases/eclipse3.1/dist/${PORTVERSION}/
PKGNAMEPREFIX=	eclipse-
DISTNAME=	org.eclipse.cdt.sdk-${PORTVERSION}-linux.x86
DIST_SUBDIR=	eclipse

MAINTAINER=	freebsd-eclipse@FreeBSD.org
COMMENT=	C/C++ IDE for Eclipse

BROKEN=		fails to fetch

RUN_DEPENDS=	${LOCALBASE}/eclipse:${PORTSDIR}/java/eclipse

NO_WRKSUBDIR=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

ECLIPSE_OS=	freebsd
.if (${ARCH} == "amd64")
ECLIPSE_ARCH=	amd64
.else
ECLIPSE_ARCH=	x86
PLIST_FILES+=	eclipse/plugins/org.eclipse.cdt.core.freebsd.x86_3.0.2/os/freebsd/x86/libpty.so \
		eclipse/plugins/org.eclipse.cdt.core.freebsd.x86_3.0.2/os/freebsd/x86/libspawner.so
.endif

MAKE_ENV+=	ECLIPSE_ARCH=${ECLIPSE_ARCH} \
		ECLIPSE_OS=${ECLIPSE_OS} \
		PORTVERSION=${PORTVERSION} \
		JAVA_HOME=${JAVA_HOME}
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

do-build:
		@${RM} ${WRKSRC}/eclipse/features/org.eclipse.cdt_${PORTVERSION}/*.orig
		@${RM} ${WRKSRC}/eclipse/features/org.eclipse.cdt.source_${PORTVERSION}/*.orig
		@${RM} ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.core.freebsd.x86_${PORTVERSION}/*.orig
		@${RM} ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.source.freebsd.gtk.x86_${PORTVERSION}/*.orig
		@${RM} ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.source.freebsd.gtk.x86_${PORTVERSION}/src/org.eclipse.cdt.core.freebsd_${PORTVERSION}/library/*.orig
		@${RM} ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.core.freebsd_${PORTVERSION}/*.orig
		@${RM} ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.core_${PORTVERSION}/*.orig
		@${RM} ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.managedbuilder.gnu.ui_${PORTVERSION}/*.orig
.if (${ARCH} == "i386")
		@(cd ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.source.freebsd.gtk.x86_${PORTVERSION}/src/org.eclipse.cdt.core.freebsd_${PORTVERSION}/library; \
		${SETENV} ${MAKE_ENV} ${GMAKE})
.endif

do-install:
		@${MKDIR} ${PREFIX}/eclipse
		@${MKDIR} ${PREFIX}/eclipse/features
		@${MKDIR} ${PREFIX}/eclipse/plugins
		@${CP} -r ${WRKSRC}/eclipse/features/org.eclipse.cdt_${PORTVERSION} ${PREFIX}/eclipse/features
		@${CP} -r ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.core.freebsd.x86_${PORTVERSION}  ${PREFIX}/eclipse/plugins
		@${CP} -r ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.core.freebsd_${PORTVERSION}  ${PREFIX}/eclipse/plugins
		@${CP} -r ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.core_${PORTVERSION}  ${PREFIX}/eclipse/plugins
		@${CP} -r ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.debug.core_${PORTVERSION}  ${PREFIX}/eclipse/plugins
		@${CP} -r ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.debug.mi.core_${PORTVERSION}  ${PREFIX}/eclipse/plugins
		@${CP} -r ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.debug.mi.ui_${PORTVERSION}  ${PREFIX}/eclipse/plugins
		@${CP} -r ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.debug.ui_${PORTVERSION}  ${PREFIX}/eclipse/plugins
		@${CP} -r ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.doc.user_${PORTVERSION}  ${PREFIX}/eclipse/plugins
		@${CP} -r ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.launch_${PORTVERSION}  ${PREFIX}/eclipse/plugins
		@${CP} -r ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.make.core_${PORTVERSION}  ${PREFIX}/eclipse/plugins
		@${CP} -r ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.make.ui_${PORTVERSION}  ${PREFIX}/eclipse/plugins
		@${CP} -r ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.managedbuilder.core_${PORTVERSION}  ${PREFIX}/eclipse/plugins
		@${CP} -r ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.managedbuilder.gnu.ui_${PORTVERSION}  ${PREFIX}/eclipse/plugins
		@${CP} -r ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.managedbuilder.ui_${PORTVERSION}  ${PREFIX}/eclipse/plugins
		@${CP} -r ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.refactoring_${PORTVERSION}  ${PREFIX}/eclipse/plugins
		@${CP} -r ${WRKSRC}/eclipse/plugins/org.eclipse.cdt.ui_${PORTVERSION}  ${PREFIX}/eclipse/plugins
		@${CP} -r ${WRKSRC}/eclipse/plugins/org.eclipse.cdt_${PORTVERSION}  ${PREFIX}/eclipse/plugins

.include <bsd.port.post.mk>
