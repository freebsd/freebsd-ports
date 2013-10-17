# Created by: olgeni@FreeBSD.org
# $FreeBSD$

PORTNAME=	wings
PORTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=	erlang

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A polygon mesh modeler written in Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang \
		${LOCALBASE}/lib/erlang/lib/esdl/include/sdl.hrl:${PORTSDIR}/devel/esdl
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
		${LOCALBASE}/lib/erlang/lib/esdl/include/sdl.hrl:${PORTSDIR}/devel/esdl

CONFLICTS=	${PORTNAME}-[0-9]*

MAKE_ENV=	ESDL_PATH=${LOCALBASE}/lib/erlang/lib/esdl
PLIST_SUB=	VERSION="${PORTVERSION}"
MAKE_JOBS_UNSAFE=yes

SUB_FILES=	${PORTNAME}.sh

USE_BZIP2=	yes
USES=		gmake

DESKTOP_ENTRIES="Wings" \
		"${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.ico" \
		"${PORTNAME}" \
		"Graphics;3DGraphics;" \
		""

PORTSCOUT=	limitw:1,odd

post-patch:
	@${REINPLACE_CMD} -e 's|$$(GCC)|${CC} -I${LOCALBASE}/include -L${LOCALBASE}/lib|g' \
		${WRKSRC}/plugins_src/accel/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/erlang/lib/${DISTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "src ebin fonts plugins textures shaders patches" \
		${STAGEDIR}${PREFIX}/lib/erlang/lib/${DISTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/${PORTNAME}.icon ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.ico

.include <bsd.port.mk>
