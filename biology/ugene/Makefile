# Created by: Hannes Hauswedell <h2+fbsdports@fsfe.org>
# $FreeBSD$

PORTNAME=	ugene
PORTVERSION=	34.0
CATEGORIES=	biology science

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Free, open-source, cross-platform bioinformatics toolkit

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	bash:shells/bash

BROKEN_aarch64=	Fails to build: invokes x86 asm

USE_GITHUB=	yes
GH_ACCOUNT=	ugeneunipro

USES=		desktop-file-utils gl qmake qt:5 shared-mime-info xorg
USE_GL=		gl glu
USE_QT=		buildtools_build linguisttools_build \
		core declarative gui opengl location network printsupport \
		script scripttools sql svg testlib webchannel webengine \
		websockets widgets xml \
		imageformats_run
USE_XORG=	x11 xtst

QMAKE_ARGS=	INSTALL_PREFIX="${PREFIX}" UGENE_INSTALL_DATA="${DATADIR}" \
		INSTALL_MANDIR="${MAN1PREFIX}/man" LRELEASE="${LRELEASE}" \
		LUPDATE="${LUPDATE}"
ALL_TARGET=	release

OPTIONS_DEFINE=	OPENCL

OPENCL_QMAKE_ON=	UGENE_OPENCL_DETECTED=1

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
# XXX: need to manually tell the build we are on x64
QMAKE_ARGS+=	CONFIG+=x64
.endif

.if ${MACHINE_CPU:Msse2}
QMAKE_ARGS+=	UGENE_SSE2_DETECTED=1
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
	@${REINPLACE_CMD} -e '422s|NULL|0|' \
		${WRKSRC}/src/plugins/smith_waterman/src/SmithWatermanAlgorithmOPENCL.cpp

.include <bsd.port.post.mk>
