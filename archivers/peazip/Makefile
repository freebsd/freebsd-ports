PORTNAME=	peazip
PORTVERSION=	10.6.1
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/giorgiotani/PeaZip/releases/download/${PORTVERSION}/
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free archiver and file compressor
WWW=		https://peazip.github.io

LICENSE=	LGPL3

ONLY_FOR_ARCHS=	aarch64 amd64 i386

USES=		cpe desktop-file-utils dos2unix fpc lazarus:flavors zip xorg
USE_XORG=	x11

CPE_VENDOR=	giorgio_tani

SUB_FILES=	pea peazip

DOS2UNIX_REGEX=		.*\.([txt]|pas|lpi|txt)

LAZARUS_PROJECT_FILES=	dev/project_pea.lpi dev/project_peach.lpi
LAZBUILD_ARGS=		-d

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5 ${PORTNAME}-qt6
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt5

ARCHIVER_FILES=		#

OPTIONS_DEFINE=		7Z ARC ZPAQ UNACE

7Z_DESC=		7z file archiver support
ARC_DESC=		Arc file archiver support
ZPAQ_DESC=		Zpaq file archiver support
UNACE_DESC=		Unace file archiver support

OPTIONS_DEFAULT=	7Z

.if ${FLAVOR:Ugtk2:Mgtk2}
USES+=		gnome
USE_GNOME+=	cairo
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:M7Z}
RUN_DEPENDS+=	7zz:archivers/7-zip
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

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|GetSelectedNodePath|Path|g' \
		-e 's|IFDEF LCLQT5|IF DEFINED\(LCLQT5\) OR DEFINED\(LCLQT6\)|g ' ${WRKSRC}/dev/peach.pas

pre-install:
	@${ECHO_CMD} "#" > ${WRKSRC}/altconf.txt
	@${ECHO_CMD} "appdata" >> ${WRKSRC}/altconf.txt

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/res/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/res/share
.for ARCHIVER in ${ARCHIVER_FILES}
	@${MKDIR} ${STAGEDIR}${DATADIR}/res/bin/${ARCHIVER}
.if ${ARCHIVER} == "7z"
	@${LN} -sf ${LOCALBASE}/bin/7zz ${STAGEDIR}${DATADIR}/res/bin/${ARCHIVER}/${ARCHIVER}
.else
	@${LN} -sf ${LOCALBASE}/bin/${ARCHIVER} ${STAGEDIR}${DATADIR}/res/bin/${ARCHIVER}/${ARCHIVER}
.endif
.endfor
	@cd ${WRKSRC}/res/share && ${COPYTREE_SHARE} "icons lang themes" ${STAGEDIR}${DATADIR}/res/share
	@cd ${WRKSRC} && ${INSTALL_DATA} altconf.txt ${STAGEDIR}${DATADIR}/res && \
			${INSTALL_PROGRAM} dev/pea ${STAGEDIR}${DATADIR}/res && \
			${INSTALL_PROGRAM} dev/peazip ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps
	@cd ${WRKSRC}/res/share/batch/freedesktop_integration && \
		${INSTALL_DATA} peazip*.desktop ${STAGEDIR}${DESKTOPDIR} && \
		${INSTALL_DATA} peazip*.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/256x256/apps/
	${INSTALL_SCRIPT} ${WRKDIR}/pea ${WRKDIR}/peazip ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.post.mk>
