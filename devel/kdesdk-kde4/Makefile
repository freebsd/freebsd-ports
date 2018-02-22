# $FreeBSD$

PORTNAME=	kdesdk
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	devel kde
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Software Development Kit

USES=		kde:4 metaport

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
CERVISIA_RUN_DEPENDS=	${KDE_PREFIX}/bin/cervisia:devel/cervisia-kde4

DEVUTILS_DESC=		KDE development utilities
DEVUTILS_RUN_DEPENDS=	${KDE_PREFIX}/bin/kuiviewer:devel/kde-dev-utils-kde4

DEVSCRIPTS_DESC=	KDE development scripts
DEVSCRIPTS_RUN_DEPENDS=	${KDE_PREFIX}/bin/kdekillall:devel/kde-dev-scripts-kde4

DOLPHIN_DESC=		Plugins for Dolphin file manager
DOLPHIN_RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/fileviewgitplugin.so:devel/dolphin-plugins-kde4

KAPPTEMPLATE_DESC=	Template generator
KAPPTEMPLATE_RUN_DEPENDS=	${KDE_PREFIX}/bin/kapptemplate:devel/kapptemplate-kde4

KATE_DESC=		KDE advanced text editor
KATE_USE=		KDE=kate_run

KATE_PATE_DESC=		Support for Python plugins in Kate
KATE_PATE_RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/katepateplugin.so:editors/kate-plugin-pate-kde4

KCACHEGRIND_DESC=	Profiler frontend
KCACHEGRIND_RUN_DEPENDS=	${KDE_PREFIX}/bin/kcachegrind:devel/kcachegrind-kde4

KIOSLAVES_DESC=		SDK related KIO slaves
KIOSLAVES_RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/kio_svn.so:devel/kdesdk-kioslaves-kde4

KOMPARE_DESC=		Diff/Patch frontend
KOMPARE_RUN_DEPENDS=	${KDE_PREFIX}/bin/kompare:textproc/kompare-kde4

LOKALIZE_DESC=		Computer-aided translation system
LOKALIZE_RUN_DEPENDS=	${KDE_PREFIX}/bin/lokalize:devel/lokalize-kde4

OKTETA_DESC=		Hex editor
OKTETA_RUN_DEPENDS=	${KDE_PREFIX}/bin/okteta:devel/okteta-kde4

POXML_DESC=		Tools to translate DocBook XML using gettext
POXML_RUN_DEPENDS=	${KDE_PREFIX}/bin/po2xml:devel/poxml-kde4

STRIGI_DESC=		Strigi analyzers for SDK file formats
STRIGI_RUN_DEPENDS=	${KDE_PREFIX}/lib/strigi/strigila_diff.so:devel/kdesdk-strigi-analyzers-kde4

THUMBNAILER_DESC=	Thumbnail generator for gettext po files
THUMBNAILER_RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/pothumbnail.so:devel/kdesdk-thumbnailers-kde4

UMBRELLO_DESC=		UML modeller
UMBRELLO_RUN_DEPENDS=	${KDE_PREFIX}/bin/umbrello:devel/umbrello-kde4

.include <bsd.port.mk>
