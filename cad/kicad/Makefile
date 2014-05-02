# Created by: Thierry Thomas <thierry@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kicad
DISTVERSION=	2013-05-18_BZR4017
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://iut-tice.ujf-grenoble.fr/cao/
DISTFILES=	${SFNAME}${EXTRACT_SUFX}	\
		${DFNAME}
EXTRACT_ONLY=	${SFNAME}${EXTRACT_SUFX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Schematic and PCB editing software

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs

CONFLICTS=	kicad-devel*

WRKSRC=		${WRKDIR}/kicad

USES=		cmake dos2unix desktop-file-utils shared-mime-info zip
# Boost templates and compiler and library support for the ISO C++ 2011 standard from include/wx-3.0
USES+=		compiler:gcc-c++11-lib
DOS2UNIX_GLOB=	*.cmake sch_bus_entry.h sch_line.h sch_no_connect.h
USE_XORG=	x11 ice xext
USE_GL=		yes
USE_WX=		3.0
WX_UNICODE=	yes
USE_GNOME=	atk	# Required by libwx_gtk2_aui-2.8.so
CXXFLAGS+=	-I${WRKSRC}/include -I${LOCALBASE}/include -DBOOST_HASH_NO_EXTENSIONS
CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE=${WX_CONFIG}	\
		-DwxUSE_UNICODE=ON -DKICAD_STABLE_VERSION=ON	\
		-DwxWidgets_wxrc_EXECUTABLE=${WXRC_CMD}
INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/stable_${DISTVERSION}

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S|^${PREFIX}/||}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext

SFNAME=		${PORTNAME}-sources-stable_${DISTVERSION}
# The stanard file is broken ATM, we have to take it from the Ubuntu package
#DFNAME=		kicad-docs+translations_only_for-stable_2013-03-15_BZR4003
DFNAME=		kicad-2013-07-07-BZR4022-stable-UBUNTU_12.04_full_with_components_doc.tgz
BINS=		cvpcb eeschema gerbview kicad pcbnew
EXTRAS2RM=	linux-non_unicode linux wings3d LINUX.README	\
		contrib_makefiles.txt running_kicad_under_W98.txt

RUN_DEPENDS+=	xpdf:${PORTSDIR}/graphics/xpdf

.include <bsd.port.options.mk>

.if {PORT_OPTIONS:MDOCS}
LICENSE+=	GFDL
LICENSE_COMB=	multi
.endif

post-extract:
	cd ${WRKDIR} && ${TAR} -xf ${DISTDIR}/${DFNAME}

post-patch:
	${MV} ${WRKSRC}/include/boost ${WRKSRC}/include/boost.orig

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/share/kicad|${DATADIR}|'		\
		-e 's|/usr/local|${PREFIX}|'				\
		-e 's|/usr/bin/xpdf|${LOCALBASE}/bin/xpdf|'		\
		-e 's|/usr/bin/konqueror|${LOCALBASE}/bin/konqueror|'	\
		${WRKSRC}/common/gestfich.cpp

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKDIR}/${PORTNAME}/share && ${COPYTREE_SHARE} library ${STAGEDIR}${DATADIR})
	(cd ${WRKDIR}/${PORTNAME}/share && ${COPYTREE_SHARE} modules ${STAGEDIR}${DATADIR})
.if ${PORT_OPTIONS:MNLS}
	${MKDIR} ${STAGEDIR}${DATADIR}/internat
	(cd ${WRKDIR}/${PORTNAME}/share/internat &&	\
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/internat)
	${RM} -f ${STAGEDIR}${DATADIR}/internat/CMakeLists.txt
	${FIND} ${STAGEDIR}${DATADIR}/internat -name kicad.po -delete
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKDIR}/${PORTNAME}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/Documentation && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
