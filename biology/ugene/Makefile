# Created by: Hannes Hauswedell <h2+fbsdports@fsfe.org>
# $FreeBSD$

PORTNAME=	ugene
DISTVERSION=	1.31.0
PORTREVISION=	1
CATEGORIES=	biology science
MASTER_SITES=	http://ugene.unipro.ru/downloads/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} QueryDesigner_UserManual.pdf \
		UniproUGENE_UserManual.pdf WorkflowDesigner_UserManual.pdf
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Free, open-source, cross-platform bioinformatics toolkit

BROKEN=		unfetchable

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	bash:shells/bash

BROKEN_aarch64=	Fails to build: invokes x86 asm

USES=		desktop-file-utils gl qmake qt:5 shared-mime-info xorg
USE_GL=		gl glu
USE_QT=		buildtools_build linguisttools_build \
		core gui network opengl printsupport script scripttools \
		sql svg testlib webkit widgets xml \
		imageformats_run
USE_XORG=	x11 xtst

QMAKE_ARGS=	INSTALL_PREFIX="${PREFIX}" UGENE_INSTALL_DATA="${DATADIR}" \
		INSTALL_MANDIR="${MAN1PREFIX}/man" LRELEASE="${LRELEASE}" \
		LUPDATE="${LUPDATE}"
ALL_TARGET=	release

DOCSDIR=	${DATADIR}/manuals

OPTIONS_DEFINE=	DOCS OPENCL
DOCS_DESC=	Install official UGENE documentation (PDF)

OPENCL_QMAKE_ON=	UGENE_OPENCL_DETECTED=1

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
# XXX: need to manually tell the build we are on x64
QMAKE_ARGS+=	CONFIG+=x64
.endif

.if ${MACHINE_CPU:Msse2}
QMAKE_ARGS+=	UGENE_SSE2_DETECTED=1
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/data/manuals
	${CP} -p ${_DISTDIR}/*.pdf ${WRKSRC}/data/manuals

post-patch:
# yes, bash is required, stuff will not execute with sh
	@${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|' \
		${WRKSRC}/src/gen_bin_script.cmd \
		${WRKSRC}/installer/_common_data/ugene
	@${REINPLACE_CMD} -e 's|-bit version|& for ${OPSYS}/${ARCH}|' \
		${WRKSRC}/src/ugeneui/src/main_window/AboutDialogController.cpp
	@${REINPLACE_CMD} 's, -lbreakpad,,' \
		${WRKSRC}/src/corelibs/U2Private/U2Private.pri \
		${WRKSRC}/src/plugins_checker/plugins_checker.pri \
		${WRKSRC}/src/ugenecl/ugenecl.pri \
		${WRKSRC}/src/ugeneui/ugeneui.pri

.include <bsd.port.post.mk>
