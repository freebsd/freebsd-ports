# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zcad
PORTVERSION=	0.9.8.4
PORTREVISION=	5
CATEGORIES=	cad
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple CAD program

USES=		fpc lazarus:flavors tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	zamtmn
USE_FPC=	cairo chm fcl-base fcl-image fcl-json fcl-stl fcl-xml opengl \
		pasjpeg rtl-extra rtl-objpas x11

MAKE_ENV=	LAZBUILD_CMD="${LAZBUILD_CMD}" \
		LAZBUILD_ARGS="${LAZBUILD_ARGS}" \
		LCL_PLATFORM="${LCL_PLATFORM}" \
		LAZARUS_DIR="${LAZARUS_DIR}" \
		INSTANTFPCCACHE="${WRKSRC}/.cache"

BUILD_WRKSRC=	${WRKSRC}/cad_source
INSTALL_WRKSRC=	${WRKSRC}/cad

LAZARUS_PROJECT_FILES=	anchordocking/anchordocking.lpk \
			fpvectorial/fpvectorialpkg.lpk \
			lclextensions/lclextensions_package.lpk \
			virtualtreeview/virtualtreeview_package.lpk \
			other/rtl-generics_for_FPC304/rtl_generics.lpk \
			components/zebase/zebase.lpk \
			components/zcontainers/zcontainers.lpk \
			components/zcontrols/zcontrols.lpk \
			components/zmath/zmath.lpk \
			components/zscriptbase/zscriptbase.lpk \
			components/zscript/zscript.lpk \
			components/zundostack/zundostack.lpk \
			components/zobjectinspector/zobjectinspector.lpk \
			components/ztoolbars/ztoolbars.lpk \
			other/AGraphLaz/lazarus/ag_vectors.lpk \
			other/AGraphLaz/lazarus/ag_attr.lpk \
			other/AGraphLaz/lazarus/ag_math.lpk \
			other/AGraphLaz/lazarus/ag_graph.lpk \
			other/uniqueinstance/uniqueinstance_package.lpk \
			utils/typeexporter.lpi

LAZBUILD_ARGS=	-d --pcp=${WRKSRC}/tmppcp

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2

PORTDOCS=	UserGuide.odt UserGuide.pdf

OPTIONS_DEFINE=		DOCS

.if ${FLAVOR:Ugtk2:Mgtk2}
MAKE_ENV+=	GUI=gtk2
.endif

post-patch:
	@${EGREP} -lR 'IFN?DEF LINUX' ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -E '/IFN?DEF LINUX/s,LINUX,UNIX,g'
	@${REINPLACE_CMD} -e '/}Linux{/d' \
		${BUILD_WRKSRC}/other/AGraphLaz/Vectors/VStream.pas \
		${BUILD_WRKSRC}/other/AGraphLaz/Vectors/VFStream.pas \
		${BUILD_WRKSRC}/other/AGraphLaz/Vectors/VFileSys.pas \
		${BUILD_WRKSRC}/other/AGraphLaz/Vectors/VStrm64.pas
	@${REINPLACE_CMD} '1,6d' ${WRKSRC}/environment/makeenv_zcad.sh

post-configure:
# OpenGL component must be fixed and rebuilt locally (to avoid touching
# filesystem outside working directory)
	${SED} -e 's,Linux,${OPSYS},' \
		${LAZARUS_DIR}/components/opengl/openglcontext.pas \
		> ${BUILD_WRKSRC}/openglcontext.pas
	${CP} ${LAZARUS_DIR}/components/opengl/glgtkglxcontext.pas \
		${LAZARUS_DIR}/components/opengl/glqtcontext.pas \
		${LAZARUS_DIR}/components/opengl/openglcontext.res \
		${BUILD_WRKSRC}
	${CP} -a ${LAZARUS_DIR}/components/fpvectorial \
		${LAZARUS_DIR}/components/anchordocking \
		${LAZARUS_DIR}/components/virtualtreeview \
		${LAZARUS_DIR}/components/lclextensions ${BUILD_WRKSRC}

post-build:
	@${MKDIR} ${WRKSRC}/cad
	@${CP} -a ${WRKSRC}/environment/runtimefiles/common/* ${WRKSRC}/cad
	@${CP} -a ${WRKSRC}/environment/runtimefiles/zcad/* ${WRKSRC}/cad
	@cd ${WRKSRC}/environment && ${SH} makeenv_zcad.sh
	@cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${LAZBUILD_CMD} \
		${LAZBUILD_ARGS} --ws=${LCL_PLATFORM} \
		--lazarusdir=${LAZARUS_DIR} zcad.lpi

do-install:
# Not ready for hier(7)-conforming installation yet
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PORTNAME}
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/${PORTNAME}
	cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} "autosave components \
		fonts images languages log menu plugins rtl sample \
		template" ${STAGEDIR}${PREFIX}/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/userguide/UserGuide.odt \
		${INSTALL_WRKSRC}/UserGuide.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

PATCH_ARGS+=	-l
