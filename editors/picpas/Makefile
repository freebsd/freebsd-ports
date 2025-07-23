PORTNAME=	picpas
PORTVERSION=	0.9.0
PORTREVISION=	19
DISTVERSIONPREFIX=	v
CATEGORIES=	editors
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Multi-platform Pascal for Microchip PIC16F microcontrollers
WWW=		https://github.com/t-edson/PicPas

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2

USES=		dos2unix fpc gnome lazarus:flavors xorg
USE_XORG=	x11
DOS2UNIX_REGEX=	.*\.([txt]|pas|lpi|txt|lfm)
USE_GITHUB=	yes
GH_ACCOUNT=	t-edson
GH_PROJECT=	PicPas
GH_TAGNAME=	7940bc3
GH_TUPLE=	t-edson:MiConfig:a4a988a:miconfig/miconfig \
		t-edson:MisUtils:742eff3:misutils/misutils  \
		t-edson:PicUtils:5f89bdf:picutils/picutils \
		t-edson:SynFacilUtils:8725237:syncfacilutils/syncfacilutils \
		t-edson:UtilsGrilla:07744b9:utilsgrilla/utilsgrilla \
		t-edson:ogEditGraf:a19b68a:ogeditgraf/ogeeditgraf \
		t-edson:t-Xpres:6665922:txpres/txpres

USE_GNOME_gtk2=	cairo
USE_GNOME+=	${USE_GNOME_${FLAVOR}}

LAZARUS_PROJECT_FILES=	Source/PicPas.lpi
LAZBUILD_ARGS=		-d

post-patch:
	${REINPLACE_CMD} 's|%%DATADIR%%|${DATADIR}|g' ${WRKSRC}/Source/Globales.pas
	${REINPLACE_CMD} 's|0.8.7|${PORTVERSION}|g' ${WRKSRC}/version.txt
	${REINPLACE_CMD} '81d' ${WRKSRC}/Source/FrameSyntaxTree.lfm
	${REINPLACE_CMD} 's|FileUtil|FileUtil, LazFileUtils|g' ${WRKSRC}/Source/FormConfig.pas

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/PicPas-freebsd ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "devices10 devices16 devices17 syntax samples temp themes units" ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
