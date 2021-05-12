# Created by: Hannes Hauswedell <h2+fbsdports@fsfe.org>

PORTNAME=	ugene
PORTVERSION=	38.0
CATEGORIES=	biology science

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Integrated bioinformatics toolkit

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_aarch64=	Fails to build: invokes x86 asm
BROKEN_riscv64=	Fails to build: invokes x86 asm
BROKEN=		Does not fetch: size mismatch (expected 23448730, actual 23446282)

RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	ugeneunipro

USES=		desktop-file-utils gl qmake qt:5 shared-mime-info sqlite xorg
USE_GL=		gl glu
USE_QT=		buildtools_build linguisttools_build \
		core gui network opengl printsupport scripttools script \
		sql svg testlib widgets xml \
		imageformats_run
USE_XORG=	x11 xtst

QMAKE_ARGS=	INSTALL_PREFIX="${PREFIX}" UGENE_INSTALL_DATA="${DATADIR}" \
		INSTALL_MANDIR="${MAN1PREFIX}/man" \
		UGENE_LRELEASE="${LRELEASE}" UGENE_LUPDATE="${LUPDATE}" \
		UGENE_USE_BUNDLED_SQLITE=0
ALL_TARGET=	release
CXXFLAGS_i386=	-msse2

OPTIONS_DEFINE=	OPENCL

OPENCL_QMAKE_ON=	UGENE_OPENCL_DETECTED=1

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
# XXX: need to manually tell the build we are on x64
QMAKE_ARGS+=	CONFIG+=x64
.endif

post-patch:
# yes, bash is required, stuff will not execute with sh
	@${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|' \
		${WRKSRC}/src/gen_bin_script.cmd \
		${WRKSRC}/installer/_common_data/ugene
	@${REINPLACE_CMD} -e 's|-bit version|& for ${OPSYS}/${ARCH}|' \
		${WRKSRC}/src/ugeneui/src/main_window/AboutDialogController.cpp
	@${REINPLACE_CMD} 's, -lbreakpad$$$$D,,' \
		${WRKSRC}/src/corelibs/U2Private/U2Private.pri \
		${WRKSRC}/src/plugins_checker/plugins_checker.pri \
		${WRKSRC}/src/ugenecl/ugenecl.pri \
		${WRKSRC}/src/ugeneui/ugeneui.pri
	@${REINPLACE_CMD} -e '218,220s|NULL)|false)|' \
		${WRKSRC}/src/plugins/GUITestBase/src/GTUtilsMdi.cpp

post-stage:
	@cd ${STAGEDIR}${PREFIX} && ${RM} bin/ecp.* lib/ugene/ecp.*

.include <bsd.port.post.mk>
