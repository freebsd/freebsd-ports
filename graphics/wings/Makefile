# Created by: olgeni@FreeBSD.org

PORTNAME=	wings
DISTVERSION=	2.2.7p1
CATEGORIES=	graphics
DIST_SUBDIR=	erlang

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Polygon mesh modeler written in Erlang

LICENSE=	Wings3D
LICENSE_NAME=	Wings 3D License # similar to TclTk license
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	erl:lang/erlang \
		erlang-cl>0:devel/erlang-cl \
		erlang-wx>0:lang/erlang-wx \
		pkg-config:devel/pkgconf
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gl tar:bzip2 eigen:3 gmake

ALL_TARGET=	lang
MAKE_JOBS_UNSAFE=yes

SUB_FILES=	${PORTNAME}.sh

USE_GITHUB=	yes
GH_ACCOUNT=	dgud
GH_PROJECT=	wings libigl:igl
GH_TAGNAME=	a41df275e v2.1.0:igl

USE_GL=		gl glu

DESKTOP_ENTRIES="Wings" \
		"${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
		"${PORTNAME}" \
		"Graphics;3DGraphics;" \
		""

post-extract:
	@${MKDIR} ${WRKSRC}/_deps
	@${LN} -s ${WRKSRC_igl} ${WRKSRC}/_deps/libigl

post-patch:
	@${REINPLACE_CMD} -e 's,include_lib("wings/,include_lib(",g' \
		${WRKSRC}/src/*.erl \
		${WRKSRC}/plugins_src/*.erl \
		${WRKSRC}/plugins_src/import_export/*.erl \
		${WRKSRC}/plugins_src/primitives/*.erl \
		${WRKSRC}/plugins_src/commands/*.erl \
		${WRKSRC}/plugins_src/commands/*.hrl \
		${WRKSRC}/plugins_src/autouv/*.erl \
		${WRKSRC}/icons/*.erl

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "ebin icons plugins textures shaders patches" \
		${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "src" \
		${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME} "-name *\.erl"
	cd ${WRKSRC} && ${COPYTREE_SHARE} "priv" \
		${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME} "-name *\.so"
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}.icon ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.ico

.include <bsd.port.mk>
