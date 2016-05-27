.if defined(CALLIGRA_L10N)
MASTER_SITES?=	KDE/${CALLIGRA_BRANCH}/calligra-${PORTVERSION}/calligra-l10n
PKGNAMEPREFIX=	${CALLIGRA_L10N:S/@/_/}-
DISTNAME=	${PORTNAME}-${CALLIGRA_L10N}-${PORTVERSION}
DIST_SUBDIR=	KDE/calligra/${PORTVERSION}/l10n

PLIST_SUB+=	LANG=${CALLIGRA_L10N}

USE_KDE4=	kdelibs automoc4
USE_QT4=	corelib xml moc_build qmake_build rcc_build uic_build
USES+=		cmake gettext tar:xz
NO_ARCH=	yes
.endif
