.if defined(CALLIGRA_L10N)
MASTER_SITES?=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR?=	${CALLIGRA_BRANCH}/calligra-${PORTVERSION}/calligra-l10n/
PKGNAMEPREFIX=	${CALLIGRA_L10N:S/@/_/}-
DISTNAME=	${PORTNAME}-${CALLIGRA_L10N}-${PORTVERSION}
DIST_SUBDIR=	KDE/calligra-l10n

CONFLICTS=	${PKGNAMEPREFIX}koffice-l10n-2.*

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_QT4=	corelib xml moc_build qmake_build rcc_build uic_build
USES=		cmake gettext
NO_ARCH=	yes
USE_XZ=		yes
.endif
