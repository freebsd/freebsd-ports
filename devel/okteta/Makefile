PORTNAME=	okteta
DISTVERSION=	0.26.60
PORTEPOCH=	1
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE hex editor (development version)
WWW=		https://apps.kde.org/okteta/

CONFLICTS_INSTALL=	okteta-qt5

LICENSE=		GPLv2 GPLv3
LICENSE_COMB=		dual
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSES/GPL-2.0-only.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSES/GPL-3.0-only.txt

USES=		cmake gettext-tools kde:6 qt:6 \
		shared-mime-info tar:xz
USE_KDE=	bookmarks colorscheme completion configwidgets \
		crash dbusaddons i18n itemviews kio parts service \
		widgetsaddons xmlgui \
		doctools:build ecm:build
USE_QT=		5compat base declarative
USE_LDCONFIG=	yes

KDE_INVENT=	09e8c273159bc303ac7e7195e43b241c0474ccce utilities
DIST_SUBDIR=	KDE/okteta

.include <bsd.port.mk>
