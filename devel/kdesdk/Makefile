PORTNAME=	kdesdk
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Software Development Kit
WWW=		https://apps.kde.org/categories/development/

USES=		kde:6 metaport qt:6

OPTIONS_DEFINE=	DEVUTILS \
		DEVSCRIPTS \
		DOLPHIN \
		KAPPTEMPLATE \
		KATE \
		KCACHEGRIND \
		KOMPARE \
		LOKALIZE \
		OKTETA \
		POXML \
		THUMBNAILER \
		UMBRELLO
OPTIONS_DEFAULT=${OPTIONS_DEFINE}

DEVUTILS_DESC=		KDE development utilities
DEVUTILS_RUN_DEPENDS=	kde-dev-utils>=${KDE_APPLICATIONS_VERSION}:devel/kde-dev-utils

DEVSCRIPTS_DESC=	KDE development scripts
DEVSCRIPTS_RUN_DEPENDS=	kde-dev-scripts>=${KDE_APPLICATIONS_VERSION}:devel/kde-dev-scripts

DOLPHIN_DESC=		Plugins for Dolphin file manager
DOLPHIN_RUN_DEPENDS=	dolphin-plugins>=${KDE_APPLICATIONS_VERSION}:devel/dolphin-plugins

KAPPTEMPLATE_DESC=	Template generator
KAPPTEMPLATE_RUN_DEPENDS=	kapptemplate>=${KDE_APPLICATIONS_VERSION}:devel/kapptemplate

KATE_DESC=		KDE advanced text editor
KATE_RUN_DEPENDS=	kate>=${KDE_APPLICATIONS_VERSION}:editors/kate

KCACHEGRIND_DESC=	Profiler frontend
KCACHEGRIND_RUN_DEPENDS=	kcachegrind>=${KDE_APPLICATIONS_VERSION}:devel/kcachegrind

KOMPARE_DESC=		Diff/Patch frontend
KOMPARE_RUN_DEPENDS=	kompare>=${KDE_APPLICATIONS_VERSION}:textproc/kompare

LOKALIZE_DESC=		Computer-aided translation system
LOKALIZE_RUN_DEPENDS=	lokalize>=${KDE_APPLICATIONS_VERSION}:devel/lokalize

OKTETA_DESC=		Hex editor
OKTETA_RUN_DEPENDS=	okteta>=0.26:devel/okteta

POXML_DESC=		Tools to translate DocBook XML using gettext
POXML_RUN_DEPENDS=	poxml>=${KDE_APPLICATIONS_VERSION}:devel/poxml

THUMBNAILER_DESC=	Thumbnail generator for gettext po files
THUMBNAILER_RUN_DEPENDS=	kdesdk-thumbnailers>=${KDE_APPLICATIONS_VERSION}:devel/kdesdk-thumbnailers

UMBRELLO_DESC=		UML modeller
UMBRELLO_RUN_DEPENDS=	umbrello>=${KDE_APPLICATIONS_VERSION}:devel/umbrello

.include <bsd.port.mk>
