# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	peazip
PORTVERSION=	6.0.0
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/giorgiotani/PeaZip/releases/download/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free archiver and file compressor

BUILD_DEPENDS=	lazbuild:editors/lazarus \
		fpcres:lang/fpc-utils

USES=		dos2unix zip
USE_FPC=	cairo fcl-base fcl-image pasjpeg rtl-objpas x11
USE_GNOME=	#

SUB_FILES=	pea pealauncher peazip

DOS2UNIX_REGEX=		.*\.([txt]|pas|lpi|txt)
LAZARUS_PROJECT_FILES=	project_pea.lpi project_peach.lpi project_gwrap.lpi
LAZBUILD_CMD=		${LOCALBASE}/bin/lazbuild -d
LCL_UNITS_DIR=		${LOCALBASE}/share/lazarus-${LAZARUS_VER}/lcl/units/${BUILDNAME}
LAZARUS_VER=		1.6.0
LAZARUS_DIR=		${LOCALBASE}/share/lazarus-${LAZARUS_VER}
ARCHIVER_FILES=		#

OPTIONS_DEFINE=		7Z ARC ZPAQ UNACE
OPTIONS_SINGLE=		LCL
OPTIONS_SINGLE_LCL=	GTK2 QT4

7Z_DESC=		7z file archiver support
ARC_DESC=		Arc file archiver support
ZPAQ_DESC=		Zpaq file archiver support
UNACE_DESC=		Unace file archiver support
GTK2_DESC=		Use gtk20 interface
QT4_DESC=		Use qt4 interface

OPTIONS_DEFAULT=	GTK2 7Z

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_FPC+=	gtk2
USE_GNOME=	gtk20
LCL_PLATFORM=	gtk2
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:editors/lazarus-lcl-gtk2
.endif

.if ${PORT_OPTIONS:MQT4}
LIB_DEPENDS+=	libQt4Pas.so:x11-toolkits/qt4pas
LCL_PLATFORM=	qt
BUILD_DEPENDS+=	${LCL_UNITS_DIR}/${LCL_PLATFORM}/interfaces.ppu:editors/lazarus-lcl-qt
.endif

.if ${PORT_OPTIONS:M7Z}
RUN_DEPENDS+=	7z:archivers/p7zip
ARCHIVER_FILES+=7z
PLIST_SUB+=	7Z=""
.else
PLIST_SUB+=	7Z="@comment "
.endif

.if ${PORT_OPTIONS:MARC}
RUN_DEPENDS+=	arc:archivers/arc
ARCHIVER_FILES+=arc
PLIST_SUB+=	ARC=""
.else
PLIST_SUB+=	ARC="@comment "
.endif

.if ${PORT_OPTIONS:MZPAQ}
RUN_DEPENDS+=	zpaq:archivers/paq
ARCHIVER_FILES+=zpaq
PLIST_SUB+=	ZPAQ=""
.else
PLIST_SUB+=	ZPAQ="@comment "
.endif

.if ${PORT_OPTIONS:MUNACE}
RUN_DEPENDS+=	unace:archivers/unace
ARCHIVER_FILES+=unace
PLIST_SUB+=	UNACE=""
.else
PLIST_SUB+=	UNACE="@comment "
.endif

do-build:
.for PROJECT_FILE in ${LAZARUS_PROJECT_FILES}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${LAZBUILD_CMD} --ws=${LCL_PLATFORM} --lazarusdir=${LAZARUS_DIR} ${PROJECT_FILE}
.endfor

pre-install:
	@${ECHO_CMD} "#" > ${WRKSRC}/altconf.txt
	@${ECHO_CMD} "appdata" >> ${WRKSRC}/altconf.txt

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/res
.for ARCHIVER in ${ARCHIVER_FILES}
	@${MKDIR} ${STAGEDIR}${DATADIR}/res/${ARCHIVER}
	@${LN} -s ${LOCALBASE}/bin/${ARCHIVER} ${STAGEDIR}${DATADIR}/res/${ARCHIVER}/${ARCHIVER}
.endfor
	@cd ${WRKSRC}/res && ${COPYTREE_SHARE} "icons lang themes" ${STAGEDIR}${DATADIR}/res
	@cd ${WRKSRC} && ${INSTALL_DATA} altconf.txt ${STAGEDIR}${DATADIR}/res && \
			${INSTALL_PROGRAM} pea pealauncher ${STAGEDIR}${DATADIR}/res && \
			${INSTALL_PROGRAM} peazip ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/FreeDesktop_integration && \
		${INSTALL_DATA} peazip.desktop ${STAGEDIR}${DESKTOPDIR} && \
		${INSTALL_DATA} peazip.png ${STAGEDIR}${PREFIX}/share/pixmaps/
	${INSTALL_SCRIPT} ${WRKDIR}/pea ${WRKDIR}/pealauncher ${WRKDIR}/peazip ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.post.mk>
