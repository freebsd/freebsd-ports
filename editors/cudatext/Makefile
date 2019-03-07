# $FreeBSD$

PORTNAME=	cudatext
PORTVERSION=	1.76.0
CATEGORIES=	editors
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Cross-platform text editor, written in Lazarus

LICENSE=	MPL20

USES=		dos2unix fpc lazarus:flavors
USE_FPC=	chm fcl-base fcl-image fcl-json fcl-stl fcl-xml pasjpeg rtl-objpas x11
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	Alexey-T
GH_PROJECT=	CudaText
GH_TUPLE=	Alexey-T:Python-for-Lazarus:586eec1:python4lazarus/python4lazarus \
		Alexey-T:ATFlatControls:ea64ab6:atflatcontrols/atflatcontrols  \
		Alexey-T:ATSynEdit:fbfd8c9:atsynedit/atsynedit \
		Alexey-T:EControl:3d97544:econtrol/econtrol \
		Alexey-T:ATSynEdit_Ex:d9e1120:atsyneditex/atsyneditex \
		Alexey-T:ATBinHex-Lazarus:cad0408:atbinhex/atbinhex \
		Alexey-T:UniqueInstance:753f823:uniqueinstance/uniqueinstance

DOS2UNIX_FILES=	app/settings_default/default.json

LAZARUS_PROJECT_FILES=	atflatcontrols/atflatcontrols/atflatcontrols_package.lpk
LAZARUS_PROJECT_FILES+=	python4lazarus/python4lazarus/python4lazarus_package.lpk
LAZARUS_PROJECT_FILES+=	atsynedit/atsynedit/atsynedit_package.lpk
LAZARUS_PROJECT_FILES+=	econtrol/econtrol/econtrol_package.lpk
LAZARUS_PROJECT_FILES+=	atsyneditex/atsynedit_ex/atsynedit_ex_package.lpk
LAZARUS_PROJECT_FILES+=	atbinhex/atbinhex/atbinhex_package.lpk
LAZARUS_PROJECT_FILES+= uniqueinstance/uniqueinstance/uniqueinstance_package.lpk
LAZARUS_PROJECT_FILES+=	app/cudatext.lpi

LAZBUILD_ARGS=		-d
LLD_UNSAFE=	yes

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt4 ${PORTNAME}-qt5
qt4_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt5
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt4

USE_FPC_gtk2=	cairo
USE_GNOME_gtk2=	cairo
USE_FPC+=	${USE_FPC_${FLAVOR}}
USE_GNOME+=	${USE_GNOME_${FLAVOR}}

post-patch:
	${REINPLACE_CMD} 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/app/proc_globdata.pas
	${REINPLACE_CMD} '636d' ${WRKSRC}/app/proc_miscutils.pas

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/app/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/app && ${COPYTREE_SHARE} "data py readme settings_default" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
