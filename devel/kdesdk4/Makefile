# $FreeBSD$

PORTNAME=	kdesdk
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Software Development Kit

USE_KDE4=	# blank, needed to get KDE4_VERSION
USES=		metaport

OPTIONS_DEFINE=	CERVISIA \
		DEVUTILS \
		DEVSCRIPTS \
		DOLPHIN \
		KAPPTEMPLATE \
		KATE \
		KATE_PATE \
		KCACHEGRIND \
		KIOSLAVES \
		KOMPARE \
		LOKALIZE \
		OKTETA \
		POXML \
		STRIGI \
		THUMBNAILER \
		UMBRELLO
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

CERVISIA_DESC=		CVS frontend
CERVISIA_RUN_DEPENDS=	${KDE4_PREFIX}/bin/cervisia:devel/cervisia

DEVUTILS_DESC=		KDE development utilities
DEVUTILS_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kuiviewer:devel/kde-dev-utils

DEVSCRIPTS_DESC=	KDE development scripts
DEVSCRIPTS_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kdekillall:devel/kde-dev-scripts

DOLPHIN_DESC=		Plugins for Dolphin file manager
DOLPHIN_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/fileviewgitplugin.so:devel/dolphin-plugins

KAPPTEMPLATE_DESC=	Template generator
KAPPTEMPLATE_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kapptemplate:devel/kapptemplate

KATE_DESC=		KDE advanced text editor
KATE_USE=		KDE4=kate_run

KATE_PATE_DESC=		Support for Python plugins in Kate
KATE_PATE_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/katepateplugin.so:editors/kate-plugin-pate

KCACHEGRIND_DESC=	Profiler frontend
KCACHEGRIND_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kcachegrind:devel/kcachegrind

KIOSLAVES_DESC=		SDK related KIO slaves
KIOSLAVES_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/kio_svn.so:devel/kdesdk4-kioslaves

KOMPARE_DESC=		Diff/Patch frontend
KOMPARE_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kompare:textproc/kompare

LOKALIZE_DESC=		Computer-aided translation system
LOKALIZE_RUN_DEPENDS=	${KDE4_PREFIX}/bin/lokalize:devel/lokalize

OKTETA_DESC=		Hex editor
OKTETA_RUN_DEPENDS=	${KDE4_PREFIX}/bin/okteta:devel/okteta

POXML_DESC=		Tools to translate DocBook XML using gettext
POXML_RUN_DEPENDS=	${KDE4_PREFIX}/bin/po2xml:devel/poxml

STRIGI_DESC=		Strigi analyzers for SDK file formats
STRIGI_RUN_DEPENDS=	${KDE4_PREFIX}/lib/strigi/strigila_diff.so:devel/kdesdk4-strigi-analyzers

THUMBNAILER_DESC=	Thumbnail generator for gettext po files
THUMBNAILER_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/pothumbnail.so:devel/kdesdk4-thumbnailers

UMBRELLO_DESC=		UML modeller
UMBRELLO_RUN_DEPENDS=	${KDE4_PREFIX}/bin/umbrello:devel/umbrello

.include <bsd.port.mk>
