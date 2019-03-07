# $FreeBSD$

PORTNAME=	dexed
PORTVERSION=	3.7.4
DISTVERSIONPREFIX=v
CATEGORIES=	editors
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	IDE for the D programming language

LICENSE=	BSL

BUILD_DEPENDS=	ldmd2:lang/ldc \
		${LOCALBASE}/lib/d/libiz.a:devel/iz \
		${LOCALBASE}/lib/d/libmir-core.a:devel/mir-core \
		${LOCALBASE}/lib/d/libdparse.a:devel/libdparse \
		${LOCALBASE}/lib/d/libstdx-allocator.a:devel/stdx-allocator
RUN_DEPENDS=	ldmd2:lang/ldc \
		dscanner:devel/d-scanner \
		dcd-client:devel/dcd-client \
		dcd-server:devel/dcd-server \
		dfmt:devel/dfmt \
		ddemangle:lang/dlang-tools

USE_GITHUB=	yes
GH_ACCOUNT=	BBasile
#GH_PROJECT=	dexed

USES=		fpc lazarus:flavors
USE_FPC=	chm fcl-base fcl-db fcl-image fcl-json fcl-net fcl-registry \
		fcl-stl fcl-web fcl-xml numlib opengl openssl pasjpeg rtl-objpas \
		regexpr rtl-extra x11
USE_XORG=	x11

DESKTOP_ENTRIES="Dexed" \
		"IDE for the D programming language" \
		"${PREFIX}/share/pixmaps/${PORTNAME}32.png" \
		"${PREFIX}/bin/${PORTNAME}" \
		"Application;IDE;Development;" \
		${TRUE}

D_LIB_DIR=	${LOCALBASE}/lib/d
D_INCLUDE_DIR=	${LOCALBASE}/include/d

LAZARUS_PROJECT_FILES=	anchordocking/anchordocking.lpk lazproj/dexed.lpi

LAZBUILD_ARGS=	-d
LLD_UNSAFE=	yes

LDMD2_CMD=	${LOCALBASE}/bin/ldmd2

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt4 ${PORTNAME}-qt5
qt4_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt5
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt4

.if ${FLAVOR:Ugtk2:Mgtk2}
USE_FPC+=	cairo
USE_GNOME+=	cairo
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%LDMD2_CMD%%|${LDMD2_CMD}|g' \
				-e 's|%%D_LIB_DIR%%|${D_LIB_DIR}|g' \
					-e 's|%%D_INCLUDE_DIR%%|${D_INCLUDE_DIR}|g' \
						 ${WRKSRC}/dastworx/build.sh
	${REINPLACE_CMD} -e 's|LINUX|UNIX|g' ${WRKSRC}/src/u_common.pas ${WRKSRC}/src/u_dcd.pas
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/src/u_compilers.pas

post-configure:
	@${MKDIR} ${WRKSRC}/tmppcp
	${CP} -a  ${LAZARUS_DIR}/components/anchordocking ${WRKSRC}

pre-build:
	@cd ${WRKSRC}/dastworx && ${SH} build.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dastworx ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/logo/*.png ${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
