# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$
#

PORTNAME=	electric-ng
PORTVERSION=	8.11
PORTREVISION=	0
CATEGORIES=	cad java
MASTER_SITES=	${MASTER_SITE_GNU} \
		http://www.staticfreesoft.com/:1
MASTER_SITE_SUBDIR=	${PORTNAME:S/-ng//}
DISTNAME=	electric-${PORTVERSION}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A sophisticated VLSI design system

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
PLIST_FILES=	%%JAVAJARDIR%%/${JARFILE} \
		bin/electric-ng
SUB_LIST+=	LIBFILES="${LIBFILES}" \
		JARFILE="${JARFILE}"
SUB_FILES=	electric-ng

OPTIONS_DEFINE=	BSH 3D IRSIM ANIM AXIS RUSSIAN
BSH_DESC=	Enable embedded java interpreter via BSH
3D_DESC=	Enable 3D visualization via Java3D
IRSIM_DESC=	Install IRSIM plugin
ANIM_DESC=	Install 3D animation plugin
AXIS_DESC=	Install 3D Axis Controller plugin
RUSSIAN_DESC=	Install Russian manual

JARFILE=	${DISTNAME}${EXTRACT_SUFX}
J3DLIB=		${LOCALBASE}/share/java/java3d/jar/j3dcore.jar
PLUGINDIR=	${PREFIX}/libexec/electric/

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBSH} || exists(${JAVALIBDIR}/bsh.jar)
RUN_DEPENDS+=	${JAVALIBDIR}/bsh.jar:${PORTSDIR}/lang/bsh
LIBFILES+=	${JAVALIBDIR}/bsh.jar
.endif

.if ${PORT_OPTIONS:MAXIS}
WITH_3D=	yes
PLUGINS+=	electricJava3D-8.11
.endif

.if ${PORT_OPTIONS:MANIM}
WITH_3D=	yes
RUN_DEPENDS+=	${JAVALIBDIR}/jmf.jar:${PORTSDIR}/java/jmf
PLUGINS+=	electricJMF-8.11
.endif

.if ${PORT_OPTIONS:M3D} || exists(${J3DLIB})
RUN_DEPENDS+=	${J3DLIB}:${PORTSDIR}/java/java3d
.endif

.if ${PORT_OPTIONS:MIRSIM}
PLUGINS+=	electricIRSIM-8.11
.endif

.if ${PORT_OPTIONS:MRUSSIAN}
PLUGINS+=	electricRussianManual-8.11
.endif

.if defined(PLUGINS)
LIBFILES+=	${PLUGINS:S,$,.jar,:S,^,${PLUGINDIR}/,}
DISTFILES=	${PLUGINS:S,$,.jar,:S,$,:1,} ${DISTNAME}${EXTRACT_SUFX}
PLIST_FILES+=	${PLUGINS:S,$,.jar,:S,^,libexec/electric/,}
.endif

do-install:
	@${MKDIR} ${JAVAJARDIR}
	${INSTALL_DATA} ${DISTDIR}/${JARFILE} ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/electric-ng ${PREFIX}/bin

.if defined(PLUGINS)
	# Install plugins
	@${MKDIR} ${PLUGINDIR}/
	${INSTALL_DATA} ${PLUGINS:S,^,${DISTDIR}/,:S,$,.jar,} ${PLUGINDIR}/
.endif

.include <bsd.port.mk>
