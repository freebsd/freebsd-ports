PORTNAME=	cudatext
PORTVERSION=	1.206.5
CATEGORIES=	editors
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Cross-platform text editor, written in Lazarus
WWW=		https://uvviewsoft.com/

LICENSE=	MPL20

USES=		desktop-file-utils dos2unix fpc gnome lazarus:flavors python xorg
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	Alexey-T
GH_PROJECT=	CudaText
GH_TUPLE=	bgrabitmap:bgrabitmap:2814b06:bgrabitmap/bgrabitmap \
		Alexey-T:Python-for-Lazarus:e85e138:python4lazarus/python4lazarus \
		Alexey-T:ATFlatControls:db9167c:atflatcontrols/atflatcontrols  \
		Alexey-T:ATSynEdit:ce183cb:atsynedit/atsynedit \
		Alexey-T:Emmet-Pascal:df69312:emmet/emmet \
		Alexey-T:EControl:80703ff:econtrol/econtrol \
		Alexey-T:ATSynEdit_Ex:8588fdf:atsyneditex/atsyneditex \
		Alexey-T:ATSynEdit_Cmp:8e7ab88:atsyneditcmp/atsyneditcmp \
		Alexey-T:ATBinHex-Lazarus:962b889:atbinhex/atbinhex \
		Alexey-T:UniqueInstance:753f823:uniqueinstance/uniqueinstance \
		Alexey-T:EncConv:ec878e9:encconv/encconv

DOS2UNIX_FILES=	app/settings_default/default.json setup/debfiles/cudatext.desktop

LAZARUS_PROJECT_FILES=	bgrabitmap/bgrabitmap/bgrabitmappack.lpk
LAZARUS_PROJECT_FILES+=	atflatcontrols/atflatcontrols/atflatcontrols_package.lpk
LAZARUS_PROJECT_FILES+=	python4lazarus/python4lazarus/python4lazarus_package.lpk
LAZARUS_PROJECT_FILES+= encconv/encconv/encconv_package.lpk
LAZARUS_PROJECT_FILES+=	atsynedit/atsynedit/atsynedit_package.lpk
LAZARUS_PROJECT_FILES+=	emmet/emmet/emmet_package.lpk
LAZARUS_PROJECT_FILES+=	econtrol/econtrol/econtrol_package.lpk
LAZARUS_PROJECT_FILES+=	atsyneditex/atsynedit_ex/atsynedit_ex_package.lpk
LAZARUS_PROJECT_FILES+=	atsyneditcmp/atsynedit_cmp/atsynedit_cmp_package.lpk
LAZARUS_PROJECT_FILES+=	atbinhex/atbinhex/atbinhex_package.lpk
LAZARUS_PROJECT_FILES+= uniqueinstance/uniqueinstance/uniqueinstance_package.lpk
LAZARUS_PROJECT_FILES+=	app/cudatext.lpi

LAZBUILD_ARGS=		-d

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5 ${PORTNAME}-qt6
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt5

USE_FPC_gtk2=	cairo
USE_GNOME_gtk2=	cairo
USE_FPC+=	${USE_FPC_${FLAVOR}}
USE_GNOME+=	${USE_GNOME_${FLAVOR}}

#WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	${REINPLACE_CMD} 's|-512||g' ${WRKSRC}/setup/debfiles/${PORTNAME}.desktop
	${REINPLACE_CMD} 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/app/proc_globdata.pas
	${REINPLACE_CMD} 's|TEncoding.UTF8|True|g' ${WRKSRC}/app/formmain_py_pluginwork.inc
	${REINPLACE_CMD} 's|ifdef LCLGTK2|if defined(LCLGTK2) and not defined(freebsd)|g' ${WRKSRC}/atsynedit/atsynedit/atsynedit.pas

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/app/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/setup/debfiles/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps
	${INSTALL_DATA} ${WRKSRC}/setup/debfiles/${PORTNAME}-512.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/${PORTNAME}.png
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/app && ${COPYTREE_SHARE} "data py readme settings_default" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
