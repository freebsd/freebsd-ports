# $FreeBSD$

PORTNAME=	cudatext
PORTVERSION=	1.84.2
PORTREVISION=	1
CATEGORIES=	editors
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Cross-platform text editor, written in Lazarus

BROKEN=		unfetchable

LICENSE=	MPL20

USES=		desktop-file-utils dos2unix fpc lazarus:flavors xorg
USE_FPC=	chm fcl-base fcl-image fcl-json fcl-stl fcl-xml pasjpeg rtl-objpas x11
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	Alexey-T
GH_PROJECT=	CudaText
GH_TUPLE=	Alexey-T:Python-for-Lazarus:586eec1:python4lazarus/python4lazarus \
		Alexey-T:ATFlatControls:34fd9d3:atflatcontrols/atflatcontrols  \
		Alexey-T:ATSynEdit:3ff9ac0:atsynedit/atsynedit \
		Alexey-T:Emmet-Pascal:0defe41:emmet/emmet \
		Alexey-T:EControl_v1:3a20fbb:econtrol/econtrol \
		Alexey-T:ATSynEdit_Ex_v1:6355c6f:atsyneditex/atsyneditex \
		Alexey-T:ATSynEdit_Cmp:2e7ac8f:atsyneditcmp/atsyneditcmp \
		Alexey-T:ATBinHex-Lazarus:cad0408:atbinhex/atbinhex \
		Alexey-T:UniqueInstance:753f823:uniqueinstance/uniqueinstance

DOS2UNIX_FILES=	app/settings_default/default.json setup/debfiles/cudatext.desktop

LAZARUS_PROJECT_FILES=	atflatcontrols/atflatcontrols/atflatcontrols_package.lpk
LAZARUS_PROJECT_FILES+=	python4lazarus/python4lazarus/python4lazarus_package.lpk
LAZARUS_PROJECT_FILES+=	atsynedit/atsynedit/atsynedit_package.lpk
LAZARUS_PROJECT_FILES+=	emmet/emmet/emmet_package.lpk
LAZARUS_PROJECT_FILES+=	econtrol/econtrol/econtrol_package.lpk
LAZARUS_PROJECT_FILES+=	atsyneditex/atsynedit_ex/atsynedit_ex_package.lpk
LAZARUS_PROJECT_FILES+=	atsyneditcmp/atsynedit_cmp/atsynedit_cmp_package.lpk
LAZARUS_PROJECT_FILES+=	atbinhex/atbinhex/atbinhex_package.lpk
LAZARUS_PROJECT_FILES+= uniqueinstance/uniqueinstance/uniqueinstance_package.lpk
LAZARUS_PROJECT_FILES+=	app/cudatext.lpi

LAZBUILD_ARGS=		-d

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2

USE_FPC_gtk2=	cairo
USE_GNOME_gtk2=	cairo
USE_FPC+=	${USE_FPC_${FLAVOR}}
USE_GNOME+=	${USE_GNOME_${FLAVOR}}

post-patch:
	${REINPLACE_CMD} 's|-512||g' ${WRKSRC}/setup/debfiles/${PORTNAME}.desktop
	${REINPLACE_CMD} 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/app/proc_globdata.pas
	${REINPLACE_CMD} 's|TEncoding.UTF8|True|g' ${WRKSRC}/app/formmain_py_pluginwork.inc
	${REINPLACE_CMD} '636d' ${WRKSRC}/app/proc_miscutils.pas

do-install:	
	${INSTALL_PROGRAM} ${WRKSRC}/app/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/setup/debfiles/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/${PORTNAME}.desktop
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps
	${INSTALL_DATA} ${WRKSRC}/setup/debfiles/${PORTNAME}-512.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/512x512/apps/${PORTNAME}.png
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/app && ${COPYTREE_SHARE} "data py readme settings_default" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
