# Created by: Hannes Hauswedell <h2+fbsdports@fsfe.org>
# $FreeBSD$

PORTNAME=	ugene
DISTVERSION=	1.12.3
CATEGORIES=	biology
MASTER_SITES=	http://ugene.unipro.ru/downloads/

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	Free, open-source, cross-platform bioinformatics toolkit

LICENSE=	GPLv2

.if !exists(/usr/include/execinfo.h)
LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo
.endif
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		qmake
USE_GL=		glu
USE_QT4=	gui webkit xml svg linguist_build moc_build qmake_build \
		qtestlib_build rcc_build uic_build imageformats_run
USE_XORG=	xtst
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

QMAKE_ARGS=	INSTALL_PREFIX=${PREFIX} UGENE_INSTALL_DATA=${DATADIR} \
		INSTALL_MANDIR=${MAN1PREFIX}/man
ALL_TARGET=	release

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 1000054
CXXFLAGS+=	-std=c++11
.endif

.if ${ARCH} == "amd64"
# XXX: need to manually tell the build we are on x64
QMAKE_ARGS+=	CONFIG+=x64
PLIST_SUB=	NOX64="@comment "
.else
PLIST_SUB=	NOX64=""
.endif

.if ${MACHINE_CPU:Msse2}
QMAKE_ARGS+=	UGENE_SSE2_DETECTED=1
.endif

post-patch:
# yes, bash is required, stuff will not execute with sh
	@${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|' \
		${WRKSRC}/src/gen_bin_script.cmd \
		${WRKSRC}/installer/_common_data/ugene
# remove BOM from files and non-latin comments; gcc 4.2 does not like them
	@${REINPLACE_CMD} -e '1s|^[^/]*|| ; /lose sequence view,/d' \
		${WRKSRC}/src/plugins/GUITestBase/src/tests/common_scenarios/smith_waterman_dialog/GTTestsSWDialog.cpp \
		${WRKSRC}/src/plugins/GUITestBase/src/tests/common_scenarios/repeat_finder/GTTestsRepeatFinder.cpp

post-configure:
	@${REINPLACE_CMD} -e '/^LFLAGS/s,-pthread,-lexecinfo &,' \
		${WRKSRC}/src/ugenecl/Makefile.Release \
		${WRKSRC}/src/ugeneui/Makefile.Release

.include <bsd.port.post.mk>
