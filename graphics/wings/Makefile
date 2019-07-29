# Created by: olgeni@FreeBSD.org
# $FreeBSD$

PORTNAME=	wings
PORTVERSION=	2.2.4
CATEGORIES=	graphics
MASTER_SITES=	SF
DIST_SUBDIR=	erlang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Polygon mesh modeler written in Erlang

LICENSE=	Wings3D
LICENSE_NAME=	Wings 3D License # similar to TclTk license
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	erl:lang/erlang \
		erlang-esdl>0:devel/erlang-esdl \
		erlang-cl>0:devel/erlang-cl \
		erlang-wx>0:lang/erlang-wx
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAKE_ENV=	ESDL_PATH=${LOCALBASE}/lib/erlang/lib/esdl
PLIST_SUB=	VERSION="${PORTVERSION}"
MAKE_JOBS_UNSAFE=yes
USE_GL=		gl glu

SUB_FILES=	${PORTNAME}.sh

USES=		gl tar:bzip2 gmake

PORTSCOUT=	limitw:1,even

DESKTOP_ENTRIES="Wings" \
		"${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
		"${PORTNAME}" \
		"Graphics;3DGraphics;" \
		""

post-patch:
	@${REINPLACE_CMD} -e 's|$$(GCC)|${CC} -I${LOCALBASE}/include -L${LOCALBASE}/lib|g' \
		${WRKSRC}/plugins_src/accel/Makefile
	@${REINPLACE_CMD} -e 's,include_lib("wings/,include_lib(",g' \
		${WRKSRC}/src/*.erl \
		${WRKSRC}/plugins_src/*.erl \
		${WRKSRC}/plugins_src/import_export/*.erl \
		${WRKSRC}/plugins_src/primitives/*.erl \
		${WRKSRC}/plugins_src/commands/*.erl \
		${WRKSRC}/plugins_src/commands/*.hrl \
		${WRKSRC}/plugins_src/autouv/*.erl \
		${WRKSRC}/icons/*.erl
#	@${FIND} ${WRKSRC} -name "*.orig" -delete

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "ebin icons plugins textures shaders patches" \
		${STAGEDIR}${PREFIX}/lib/erlang/lib/${DISTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "src" \
		${STAGEDIR}${PREFIX}/lib/erlang/lib/${DISTNAME} "-name *\.erl"
	${LN} -sf ${DISTNAME} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}.icon ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.ico
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/lib/erlang/lib/${DISTNAME}/plugins/accel/*.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${DISTNAME}/plugins/accel/*.so
	${CHMOD} u-w ${STAGEDIR}${PREFIX}/lib/erlang/lib/${DISTNAME}/plugins/accel/*.so

.include <bsd.port.mk>
