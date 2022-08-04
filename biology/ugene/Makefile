PORTNAME=	ugene
PORTVERSION=	40.1
CATEGORIES=	biology science

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Integrated bioinformatics toolkit

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_aarch64=	fails to build: invokes x86 asm
BROKEN_armv7=	fails to build: src/SendReportDialog.cpp:435:20: error: invalid output constraint '=a' in asm, see https://github.com/ugeneunipro/ugene/issues/919
BROKEN_riscv64=	fails to build: invokes x86 asm

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

.if ${ARCH} == i386
QMAKE_ARGS+=	CONFIG+=x86
.endif

post-patch:
# yes, bash is required, stuff will not execute with sh
	@${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|' \
		${WRKSRC}/src/gen_bin_script.cmd \
		${WRKSRC}/etc/shared/ugene ${WRKSRC}/etc/shared/ugened
	@${REINPLACE_CMD} -e 's|-bit version|& for ${OPSYS}/${ARCH}|' \
		${WRKSRC}/src/ugeneui/src/main_window/AboutDialogController.cpp
	@${REINPLACE_CMD} 's, -lbreakpad$$$$D,,' \
		${WRKSRC}/src/corelibs/U2Private/U2Private.pri \
		${WRKSRC}/src/plugins_checker/plugins_checker.pri \
		${WRKSRC}/src/ugenecl/ugenecl.pri \
		${WRKSRC}/src/ugeneui/ugeneui.pri
	@${REINPLACE_CMD} -e '/ugene\.desktop/s,share,&d,' \
		${WRKSRC}/ugene.pri

post-stage:
	@cd ${STAGEDIR}${PREFIX} && ${RM} bin/ecp.* lib/ugene/ecp.*

.include <bsd.port.post.mk>
