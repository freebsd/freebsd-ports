# New ports collection makefile for:	rigsofrods
# Date created:		05 Mar 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rigsofrods
PORTVERSION=	0.36.2
CATEGORIES=	games
MASTER_SITES=	SF
DISTFILES=	${PORTNAME}-source-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-contents-${PORTVERSION}${EXTRACT_SUFX}
EXTRACT_ONLY=	${PORTNAME}-source-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Truck, car, airplane and boat simulator with advanced physics

LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal \
		zzip.13:${PORTSDIR}/devel/zziplib \
		freetype.9:${PORTSDIR}/print/freetype2 \
		CEGUIBase.3:${PORTSDIR}/graphics/cegui \
		freeimage.3:${PORTSDIR}/graphics/freeimage
BUILD_DEPENDS=	${LOCALBASE}/lib/libOIS.so:${PORTSDIR}/devel/ois \
		unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	${LOCALBASE}/lib/libOIS.so:${PORTSDIR}/devel/ois \
		xset:${PORTSDIR}/x11/xset

USE_ZIP=	yes
USE_XORG=	x11 xt xaw sm ice xext
WRKSRC=		${WRKDIR}/${PORTNAME}-source-${PORTVERSION}/build
USE_WX=		2.6+
WX_UNICODE=	yes
MAKE_JOBS_SAFE=	yes

USE_CMAKE=	yes
# CG unavailable for FreeBSD
CMAKE_ARGS=	-DROR_BUILD_HYDRAX=TRUE \
		-DROR_BUILD_PAGED=TRUE \
		-DROR_BUILD_LUASCRIPT=TRUE \
		-DROR_BUILD_CONFIGURATOR=TRUE \
		-DOGRE_BUILD_PLUGIN_CG=FALSE \
		-DLOCALBASE="${LOCALBASE}" \
		-DwxWidgets_CONFIG_EXECUTABLE="${WX_CONFIG}"
CMAKE_USE_PTHREAD=	yes

PORTDOCS=	*

SUB_FILES=	RoR.sh rorconfig.sh

LIB_FILES=	dependencies/ogrenew/OgreMain/libOgreMain.so.1 \
		dependencies/ogrenew/PlugIns/OctreeSceneManager/Plugin_OctreeSceneManager.so \
		dependencies/ogrenew/PlugIns/ParticleFX/Plugin_ParticleFX.so \
		dependencies/ogrenew/RenderSystems/GL/RenderSystem_GL.so \
		dependencies/Caelum-2006-11-09/libcaelum.so \
		dependencies/mygui/libmygui.so \
		dependencies/hydrax/libhydrax.so \
		dependencies/mysocketw/libmysocketw.so

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-extract:
	@${RM} -rf ${WRKSRC}/dependencies/ogrenew/Dependencies

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|; \
		s|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/main/source/Settings.cpp \
		${WRKSRC}/configurator/source/configurator.cpp
.if ${OSVERSION} >= 800067
# after strnlen was introduced, use it
	@${REINPLACE_CMD} -e '/strnlen/ d' ${WRKSRC}/main/CMakeLists.txt \
		${WRKSRC}/configurator/CMakeLists.txt
.endif

do-install:
# libs
	${MKDIR} ${PREFIX}/lib/${PORTNAME}
.for f in ${LIB_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/lib/${PORTNAME}
.endfor

# binaries
	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/main/RoR ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/configurator/rorconfig ${PREFIX}/libexec/${PORTNAME}

# data
	${MKDIR} ${DATADIR}
	${SED} -e '/Plugin_CgProgramManager/ s|^|#|' \
		< ${WRKSRC}/bin/release/linux/plugins.cfg \
		> ${DATADIR}/plugins.cfg
	${UNZIP_CMD} -qq -o -d ${DATADIR} ${DISTDIR}/${PORTNAME}-contents-${PORTVERSION}.zip \
		languages/\* resources/\* skeleton/\* streams/\*

# wrappers
	${INSTALL_SCRIPT} ${WRKDIR}/RoR.sh ${PREFIX}/bin/RoR
	${INSTALL_SCRIPT} ${WRKDIR}/rorconfig.sh ${PREFIX}/bin/rorconfig

#docs
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${UNZIP_CMD} -qq -o -d ${DOCSDIR} ${DISTDIR}/${PORTNAME}-contents-${PORTVERSION}.zip \
		\*.pdf
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
