# Created by: Hannes Hauswedell <h2+fbsdports@fsfe.org>
# $FreeBSD$

PORTNAME=	ugene
DISTVERSION=	1.22.0
PORTREVISION=	1
CATEGORIES=	biology science
MASTER_SITES=	http://ugene.unipro.ru/downloads/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} QueryDesigner_UserManual.pdf \
		UniproUGENE_UserManual.pdf WorkflowDesigner_UserManual.pdf
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Free, open-source, cross-platform bioinformatics toolkit

LICENSE=	GPLv2

RUN_DEPENDS=	bash:shells/bash

BROKEN_aarch64=	Fails to build: invokes x86 asm

USES=		desktop-file-utils execinfo qmake
USE_GL=		glu
USE_QT5=	buildtools_build linguisttools_build scripttools_build \
		gui network printsupport script sql svg webkit widgets xml \
		imageformats_run

QMAKE_ARGS=	INSTALL_PREFIX="${PREFIX}" UGENE_INSTALL_DATA="${DATADIR}" \
		INSTALL_MANDIR="${MAN1PREFIX}/man" LRELEASE="${LRELEASE}" \
		LUPDATE="${LUPDATE}"
ALL_TARGET=	release

# Required for Google Test code
CXXFLAGS+=	-std=c++11

DOCSDIR=	${DATADIR}/manuals

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Install official UGENE documentation (PDF)

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
# XXX: need to manually tell the build we are on x64
QMAKE_ARGS+=	CONFIG+=x64
PLIST_SUB+=	NOX64="@comment "
.else
PLIST_SUB+=	NOX64=""
.endif

.if ${MACHINE_CPU:Msse2}
QMAKE_ARGS+=	UGENE_SSE2_DETECTED=1
PLIST_SUB+=	SSE2=""
.else
PLIST_SUB+=	SSE2="@comment "
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
	@${REINPLACE_CMD} -e '/unix_not_mac/,+11d' \
		${WRKSRC}/src/corelibs/U2Core/U2Core.pri
	@${REINPLACE_CMD} 's, -lbreakpad,,' \
		${WRKSRC}/src/corelibs/U2Private/U2Private.pri \
		${WRKSRC}/src/plugins_checker/plugins_checker.pri \
		${WRKSRC}/src/ugenecl/ugenecl.pri \
		${WRKSRC}/src/ugeneui/ugeneui.pri

.include <bsd.port.post.mk>
