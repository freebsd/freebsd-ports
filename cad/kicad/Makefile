# New ports collection makefile for:  kicad
# Date created:               29 November 2005
# Whom:                       Thierry Thomas <thierry@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kicad
DISTVERSION=	2010-05-05-BZR2356
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://iut-tice.ujf-grenoble.fr/cao/	\
		http://iut-tice.ujf-grenoble.fr/cao/
DISTFILES=	${SFNAME}-stable${EXTRACT_SUFX}	\
		${DFNAME}.tgz
EXTRACT_ONLY=	${SFNAME}-stable${EXTRACT_SUFX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Schematic and PCB editing software

LIB_DEPENDS=	boost_thread.4:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/share/kicad/library/74xx.dcm:${PORTSDIR}/cad/kicad-library

CONFLICTS=	kicad-devel*

WRKSRC=		${WRKDIR}/kicad

USE_ZIP=	yes
USE_DOS2UNIX=	*.cmake
USE_CMAKE=	yes
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

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

SFNAME=		${PORTNAME}-sources-${DISTVERSION}
DFNAME=		doc_components-${DISTVERSION}-stable
BINS=		cvpcb eeschema gerbview kicad pcbnew
EXTRAS2RM=	linux-non_unicode linux wings3d LINUX.README	\
		contrib_makefiles.txt running_kicad_under_W98.txt

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/konqueror)
RUN_DEPENDS+=	konqueror:${PORTSDIR}/x11/kdebase3
.else
RUN_DEPENDS+=	xpdf:${PORTSDIR}/graphics/xpdf
.endif

.if !defined(NOPORTDOCS)
post-extract:
	cd ${WRKSRC} && ${TAR} -xf ${DISTDIR}/${DFNAME}.tgz
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/share/kicad|${DATADIR}|'		\
		-e 's|/usr/local|${PREFIX}|'				\
		-e 's|/usr/bin/xpdf|${LOCALBASE}/bin/xpdf|'		\
		-e 's|/usr/bin/konqueror|${LOCALBASE}/bin/konqueror|'	\
		${WRKSRC}/common/gestfich.cpp

post-install:
.if !defined(WITHOUT_NLS)
	${MKDIR} ${DATADIR}/internat
	(cd ${WRKSRC}/internat &&	\
		${COPYTREE_SHARE} \* ${DATADIR}/internat)
	${RM} ${DATADIR}/internat/CMakeLists.txt
	${FIND} ${DATADIR}/internat -name kicad.po -delete
.endif
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
