# Created by: Thierry Thomas <thierry@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kicad
DISTVERSION=	2010-05-05-BZR2356
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://iut-tice.ujf-grenoble.fr/cao/	\
		http://iut-tice.ujf-grenoble.fr/cao/
DISTFILES=	${SFNAME}-stable${EXTRACT_SUFX}	\
		${DFNAME}.tgz
EXTRACT_ONLY=	${SFNAME}-stable${EXTRACT_SUFX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Schematic and PCB editing software

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/share/kicad/library/74xx.dcm:${PORTSDIR}/cad/kicad-library

CONFLICTS=	kicad-devel*

WRKSRC=		${WRKDIR}/kicad

USES=		cmake dos2unix desktop-file-utils shared-mime-info zip
DOS2UNIX_GLOB=	*.cmake
USE_GL=		yes
USE_WX=		2.8
WX_UNICODE=	yes
USE_GNOME=	atk	# Required by libwx_gtk2_aui-2.8.so
CXXFLAGS+=	-I${WRKSRC}/include -I${LOCALBASE}/include
CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE=${WX_CONFIG}	\
		-DwxWidgets_wxrc_EXECUTABLE=${WXRC_CMD}
INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/${SFNAME}

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S|^${PREFIX}/||}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext

SFNAME=		${PORTNAME}-sources-${DISTVERSION}
DFNAME=		doc_components-${DISTVERSION}-stable
BINS=		cvpcb eeschema gerbview kicad pcbnew
EXTRAS2RM=	linux-non_unicode linux wings3d LINUX.README	\
		contrib_makefiles.txt running_kicad_under_W98.txt

RUN_DEPENDS+=	xpdf:${PORTSDIR}/graphics/xpdf

post-extract:
	cd ${WRKSRC} && ${TAR} -xf ${DISTDIR}/${DFNAME}.tgz

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/share/kicad|${DATADIR}|'		\
		-e 's|/usr/local|${PREFIX}|'				\
		-e 's|/usr/bin/xpdf|${LOCALBASE}/bin/xpdf|'		\
		-e 's|/usr/bin/konqueror|${LOCALBASE}/bin/konqueror|'	\
		${WRKSRC}/common/gestfich.cpp

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/internat
	(cd ${WRKSRC}/internat &&	\
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/internat)
	${RM} -f ${STAGEDIR}${DATADIR}/internat/CMakeLists.txt
	${FIND} ${STAGEDIR}${DATADIR}/internat -name kicad.po -delete
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
