PORTNAME=	komodo
PORTVERSION=	1.6.0
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/stable/komodo/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE todo manager that uses todo.txt specification
WWW=		https://apps.kde.org/komodo

USES=		cmake gettext kde:6 qt:6 tar:xz
USE_KDE=	colorscheme config coreaddons dbusaddons doctools \
		guiaddons i18n iconthemes itemmodels kirigami2 \
		kirigami-addons qqc2-desktop-style \
		ecm:build
USE_QT=		base declarative

.include <bsd.port.mk>
