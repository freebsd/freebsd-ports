# Created by: Hannes Hauswedell <h2+fbsdports@fsfe.org>
# $FreeBSD$

PORTNAME=	ugene
DISTVERSION=	1.16.2
CATEGORIES=	biology science
MASTER_SITES=	http://ugene.unipro.ru/downloads/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} QueryDesigner_UserManual.pdf \
		UniproUGENE_UserManual.pdf WorkflowDesigner_UserManual.pdf
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Free, open-source, cross-platform bioinformatics toolkit

LICENSE=	GPLv2

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		execinfo qmake
USE_GL=		glu
USE_QT4=	corelib gui network script webkit xml \
		linguist_build moc_build qmake_build qtestlib_build \
		rcc_build scripttools_build uic_build \
		imageformats_run
USE_XORG=	xtst
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

QMAKE_ARGS=	INSTALL_PREFIX="${PREFIX}" UGENE_INSTALL_DATA="${DATADIR}" \
		INSTALL_MANDIR="${MAN1PREFIX}/man"
ALL_TARGET=	release

DOCSDIR=	${DATADIR}/manuals

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Install official UGENE documentation (PDF)

.include <bsd.port.pre.mk>

# Required for Google Test code
.if ${OSVERSION} > 1000054
CXXFLAGS+=	-std=c++11
.endif

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
	${CP} -p ${_DISTDIR}/*.pdf ${WRKSRC}/data/manuals

post-patch:
# yes, bash is required, stuff will not execute with sh
	@${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|' \
		${WRKSRC}/src/gen_bin_script.cmd \
		${WRKSRC}/installer/_common_data/ugene
	@${REINPLACE_CMD} -e '/readproc\.h/d' \
		${WRKSRC}/src/corelibs/U2Core/src/globals/AppResources.cpp
	@${REINPLACE_CMD} -e 's|-bit version|& for ${OPSYS}|' \
		${WRKSRC}/src/ugeneui/src/main_window/AboutDialogController.cpp
	@${REINPLACE_CMD} -e '/ifdef/s|Q_OS_LINUX|Q_OS_UNIX|' \
		${WRKSRC}/src/corelibs/U2Test/src/gui_tests/GUITestLauncher.cpp
.for x in ugenecl ugeneui plugins_checker
	@${ECHO_CMD} 'LIBS += -lexecinfo' >> ${WRKSRC}/src/${x}/${x}.pro
.endfor
# remove BOM that gcc4.2 trips upon
	@env LANG=C ${REINPLACE_CMD} -e 's,^...,,' \
		${WRKSRC}/src/include/U2Formats/MysqlUpgradeTask.h

.include <bsd.port.post.mk>
