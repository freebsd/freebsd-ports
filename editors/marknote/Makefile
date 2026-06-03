PORTNAME=	marknote
PORTVERSION=	1.6.0
CATEGORIES=	editors kde
MASTER_SITES=	KDE/stable/marknote/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Simple markdown note management app
WWW=		https://apps.kde.org/marknote/

LIB_DEPENDS=	libmd4c.so:textproc/md4c

USES=		cmake gettext-tools kde:6 pkgconfig qt:6 tar:xz
USE_KDE=	colorscheme config coreaddons i18n iconthemes itemmodels \
		kirigami2 kirigami-addons mime notifications windowsystem \
		syntaxhighlighting:run \
		ecm:build
USE_QT=		base declarative svg

.include <bsd.port.mk>
