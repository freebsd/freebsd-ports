# Created by: Thierry Thomas <thierry@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kicad
DISTVERSION=	20140622%2Bbzr4027
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	https://launchpadlibrarian.net/179199115/
DISTNAME=	${PORTNAME}_0.${DISTVERSION}.orig

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Schematic and PCB editing software

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs
BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
RUN_DEPENDS=	xpdf:${PORTSDIR}/graphics/xpdf

CONFLICTS=	kicad-devel*

USES=		cmake dos2unix desktop-file-utils shared-mime-info tar:xz
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

WRKSRC=		${WRKDIR}/${PORTNAME}-0.${DISTVERSION:C/%2B/+/}

PLIST_SUB=	DESKTOPDIR=${DESKTOPDIR:S|^${PREFIX}/||}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext

BINS=		cvpcb eeschema gerbview kicad pcbnew
EXTRAS2RM=	linux-non_unicode linux wings3d LINUX.README	\
		contrib_makefiles.txt running_kicad_under_W98.txt


.include <bsd.port.options.mk>

.if {PORT_OPTIONS:MDOCS}
LICENSE+=	GFDL
LICENSE_COMB=	multi
.endif

post-patch:
	${MV} ${WRKSRC}/include/boost ${WRKSRC}/include/boost.orig

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/share/kicad|${DATADIR}|'		\
		-e 's|/usr/local|${PREFIX}|'				\
		-e 's|/usr/bin/evince|${LOCALBASE}/bin/xpdf|'		\
		-e 's|/usr/bin/kpdf|${LOCALBASE}/bin/okular|'		\
		-e 's|/usr/bin/xpdf|${LOCALBASE}/bin/xpdf|'		\
		-e 's|/usr/bin/konqueror|${LOCALBASE}/bin/konqueror|'	\
		-e 's|/usr/bin/xdg-open|${LOCALBASE}/bin/xdg-open|'	\
		${WRKSRC}/common/gestfich.cpp

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/library && ${COPYTREE_SHARE} library ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/library && ${COPYTREE_SHARE} modules ${STAGEDIR}${DATADIR})
.if ${PORT_OPTIONS:MNLS}
	${MKDIR} ${STAGEDIR}${DATADIR}/internat
	(cd ${WRKSRC}/doc/internat &&	\
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/internat)
	${RM} -f ${STAGEDIR}${DATADIR}/internat/CMakeLists.txt
	${FIND} ${STAGEDIR}${DATADIR}/internat -name kicad.po -delete
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/Documentation && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
.endif

.include <bsd.port.mk>
