# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	coedit
DISTVERSION=	3_update_3
PORTREVISION=	1
CATEGORIES=	editors

MAINTAINER=	acm@FreeBSD.org
COMMENT=	IDE for the D programming language

LICENSE=	BSL

BUILD_DEPENDS=	lazbuild:editors/lazarus \
		ldmd2:lang/ldc \
		${LOCALBASE}/lib/d/libiz.a:devel/iz \
		${LOCALBASE}/lib/d/libdparse.a:devel/libdparse
RUN_DEPENDS=	ldmd2:lang/ldc \
		dscanner:devel/d-scanner \
		dcd-client:devel/dcd-client \
		dcd-server:devel/dcd-server \
		dfmt:devel/dfmt \
		ddemangle:lang/dlang-tools

USE_GITHUB=	yes
GH_ACCOUNT=	BBasile
GH_PROJECT=	Coedit

USE_FPC=	cairo fcl-base fcl-db fcl-image fcl-json fcl-net fcl-registry \
		fcl-stl fcl-web fcl-xml numlib openssl pasjpeg rtl-objpas \
		regexpr rtl-extra x11

DESKTOP_ENTRIES="Coedit" \
		"IDE for the D programming language" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PREFIX}/bin/${PORTNAME}" \
		"Application;IDE;Development;" \
		${TRUE}

OPTIONS_SINGLE=		LCL
OPTIONS_SINGLE_LCL=	GTK2 QT4

GTK2_DESC=		Use gtk20 interface
QT4_DESC=		Use qt4 interface

OPTIONS_DEFAULT=	GTK2

D_LIB_DIR=	${LOCALBASE}/lib/d
D_INCLUDE_DIR=	${LOCALBASE}/include/d
PROJECT_FILE=	lazproj/coedit.lpi
LAZARUS_VER=	1.6.4
LAZBUILD_CMD=	${LOCALBASE}/bin/lazbuild
LAZARUS_DIR=	${WRKSRC}/lazarus-${LAZARUS_VER}
LCL_UNITS_DIR=	${LOCALBASE}/share/lazarus-${LAZARUS_VER}/lcl/units/${BUILDNAME}
LDMD2_CMD=	${LOCALBASE}/bin/ldmd2

GTK2_BUILD_DEPENDS=	${LCL_UNITS_DIR}/gtk2/interfaces.ppu:editors/lazarus-lcl-gtk2
GTK2_USE=		GNOME=gtk20 FPC=gtk2
GTK2_MAKE_ENV=		GUI=gtk2
GTK2_VARS=		LCL_PLATFORM=gtk2

QT4_BUILD_DEPENDS=	${LCL_UNITS_DIR}/qt/interfaces.ppu:editors/lazarus-lcl-qt
QT4_LIB_DEPENDS=	libQt4Pas.so:x11-toolkits/qt4pas
QT4_MAKE_ENV=		GUI=qt
QT4_VARS=		LCL_PLATFORM=qt

post-patch:
	${REINPLACE_CMD} -e 's|%%LDMD2_CMD%%|${LDMD2_CMD}|g' \
				-e 's|%%D_LIB_DIR%%|${D_LIB_DIR}|g' \
					-e 's|%%D_INCLUDE_DIR%%|${D_INCLUDE_DIR}|g' \
						 ${WRKSRC}/dastworx/build.sh
	${REINPLACE_CMD} -e 's|LINUX|UNIX|g' ${WRKSRC}/src/ce_common.pas ${WRKSRC}/src/ce_dcd.pas
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/src/ce_compilers.pas

pre-build:
	@${MKDIR} ${WRKSRC}/tmppcp
	@${MKDIR} ${LAZARUS_DIR}
	@cd ${LOCALBASE}/share/lazarus-${LAZARUS_VER} && \
		${FIND} * -type d -exec ${MKDIR} ${LAZARUS_DIR}/{} \;
	@cd ${LOCALBASE}/share/lazarus-${LAZARUS_VER} && \
		${FIND} * -type f -exec ${LN} -fs ${LOCALBASE}/share/lazarus-${LAZARUS_VER}/{} ${LAZARUS_DIR}/{} \;
	@${FIND} ${LAZARUS_DIR} -type d -name ${BUILDNAME} -type d -print0 | \
		${XARGS} -0 ${RM} -R

do-build:
	@cd ${WRKSRC}/dastworx && ${SH} build.sh
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --ws=${LCL_PLATFORM} --lazarusdir=${LAZARUS_DIR} --pcp=${WRKSRC}/tmppcp ${PROJECT_FILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/coedit ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dastworx ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/logo/coedit.png ${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
