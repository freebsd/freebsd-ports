PORTNAME=	okteta
DISTVERSION=	0.26.23
PORTEPOCH=	1
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE hex editor
WWW=		https://www.kde.org/applications/utilities/okteta/

LICENSE=		GPLv2 GPLv3
LICENSE_COMB=		dual
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSES/GPL-2.0-only.txt
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSES/GPL-3.0-only.txt

LIB_DEPENDS=	libqca-qt5.so:devel/qca@qt5

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 \
		shared-mime-info tar:xz xorg
USE_KDE=	attica auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons doctools i18n iconthemes itemviews \
		jobwidgets kcmutils kio newstuff parts service solid sonnet \
		textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus declarative designer gui network \
		printsupport script scripttools widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11
USE_LDCONFIG=	yes

.include <bsd.port.mk>
