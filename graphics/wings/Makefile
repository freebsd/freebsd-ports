# Created by: olgeni@FreeBSD.org
# $FreeBSD$

PORTNAME=	wings
PORTVERSION=	1.4.1
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF
DIST_SUBDIR=	erlang

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Polygon mesh modeler written in Erlang

LICENSE=	Wings3D
LICENSE_NAME=	Wings 3D License # similar to TclTk license
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	erl:lang/erlang \
		erlang-esdl>0:devel/erlang-esdl
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAKE_ENV=	ESDL_PATH=${LOCALBASE}/lib/erlang/lib/esdl
PLIST_SUB=	VERSION="${PORTVERSION}"
MAKE_JOBS_UNSAFE=yes

SUB_FILES=	${PORTNAME}.sh

USES=		tar:bzip2 gmake

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
	@${FIND} ${WRKSRC} -name "*.orig" -delete

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "src ebin fonts plugins textures shaders patches" \
		${STAGEDIR}${PREFIX}/lib/erlang/lib/${DISTNAME}
	${LN} -sf ${DISTNAME} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}.icon ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.ico
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/lib/erlang/lib/${DISTNAME}/plugins/accel/*.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${DISTNAME}/plugins/accel/*.so
	${CHMOD} u-w ${STAGEDIR}${PREFIX}/lib/erlang/lib/${DISTNAME}/plugins/accel/*.so

.include <bsd.port.mk>
