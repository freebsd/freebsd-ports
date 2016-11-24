# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	electric
PORTVERSION=	9.07
CATEGORIES=	cad java
MASTER_SITES=	GNU/${PORTNAME:S/-ng//} \
		http://www.staticfreesoft.com/:1 \
		http://www.staticfreesoft.com/jmanual/:2
PKGNAMESUFFIX=	-ng
EXTRACT_SUFX=
DISTFILES+=	${PORTNAME}Binary-${PORTVERSION}.jar
EXTRACT_ONLY=

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Sophisticated VLSI design system

LICENSE=	GPLv3

EXTRACT_DEPENDS=	${UNZIP_CMD}:archivers/unzip

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
SUB_LIST+=	LIBFILES="${LIBFILES}" \
		JARFILE="${JARFILE}"
SUB_FILES=	electric-ng
PLIST_SUB+=	VERSION="${PORTVERSION}"

OPTIONS_DEFINE=	BSH 3D IRSIM DOCS
BSH_DESC=	Enable embedded java interpreter via BSH
3D_DESC=	Enable 3D visualization via Java3D
IRSIM_DESC=	Install IRSIM and 3D animation plugin

OPTIONS_DEFAULT=	IRSIM MANUAL 3D
OPTIONS_SUB=	yes

JARFILE=	${PORTNAME}Binary-${PORTVERSION}.jar
J3DLIB=		${JAVA_HOME}/jre/lib/ext/j3dcore.jar
PLUGINDIR=	${PREFIX}/libexec/${PORTNAME}${PKGNAMESUFFIX}

DESKTOP_ENTRIES="Electric-NG" "${COMMENT}" "${PORTNAME}${PKGNAMESUFFIX}" \
			"${PORTNAME}${PKGNAMESUFFIX}" "Development;Electronics;Engineering;" false

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBSH} || exists(${JAVALIBDIR}/bsh.jar)
RUN_DEPENDS+=	${JAVALIBDIR}/bsh.jar:lang/bsh
LIBFILES+=	${JAVALIBDIR}/bsh.jar
.endif

.if ${PORT_OPTIONS:M3D} || exists(${J3DLIB})
RUN_DEPENDS+=	${J3DLIB}:java/java3d
.endif

.if ${PORT_OPTIONS:MIRSIM}
RUN_DEPENDS+=	${JAVALIBDIR}/jmf.jar:java/jmf
PLUGINS+=	electricSFS-${PORTVERSION}
LIBFILES+=	${PREFIX}/libexec/${PORTNAME}${PKGNAMESUFFIX}/electricSFS-${PORTVERSION}.jar
.endif

DISTFILES+=	ElectricManual-${PORTVERSION}.pdf:2

.if defined(PLUGINS)
DISTFILES+=	electricSFS-${PORTVERSION}.jar:1
.endif

post-extract:
	@(cd ${DISTDIR}/${DIST_SUBDIR} && ${UNZIP_CMD} -d ${WRKDIR} ${PORTNAME}Binary-${PORTVERSION}.jar \
		com/sun/electric/tool/user/help/helphtml/iconplug.png)

do-install:
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}${PKGNAMESUFFIX}
	${INSTALL_DATA} ${DISTDIR}/ElectricManual-${PORTVERSION}.pdf ${STAGEDIR}${DOCSDIR}${PKGNAMESUFFIX}
	${INSTALL_DATA} ${DISTDIR}/${JARFILE} ${STAGEDIR}${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/electric-ng ${STAGEDIR}${PREFIX}/bin

	${INSTALL_DATA} ${WRKDIR}/com/sun/electric/tool/user/help/helphtml/iconplug.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}${PKGNAMESUFFIX}.png

.if defined(PLUGINS)
	# Install plugins
	@${MKDIR} ${STAGEDIR}${PLUGINDIR}/
	${INSTALL_DATA} ${DISTDIR}/electricSFS-${PORTVERSION}.jar ${STAGEDIR}${PLUGINDIR}/
.endif

.include <bsd.port.mk>
