.if defined(KOFFICE2_L10N)
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	uic_build moc_build qmake_build rcc_build xml
USE_GETTEXT=	yes
USE_KDE4=	kdelibs kdehier kdeprefix automoc4
USE_CMAKE=	yes
MASTER_SITES?=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR?=	${KOFFICE2_BRANCH}/koffice-${PORTVERSION}/koffice-l10n/
PKGNAMEPREFIX=	${KOFFICE2_L10N:S/@/_/}-
DISTNAME=	${PORTNAME}-${KOFFICE2_L10N}-${PORTVERSION}
DIST_SUBDIR?=	KDE/kde-l10n
.endif
