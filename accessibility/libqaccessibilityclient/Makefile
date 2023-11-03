PORTNAME=	libqaccessibilityclient
DISTVERSION=	0.5.0
CATEGORIES=	accessibility kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Helper to make writing accessibility tools easier
WWW=		https://api.kde.org/libqaccessibilityclient/html/index.html

LICENSE=		LGPL21 LGPL3
LICENSE_COMB=		dual
LICENSE_FILE_LGPL21=	${WRKSRC}/LICENSES/LGPL-2.1-only.txt
LICENSE_FILE_LGPL3=	${WRKSRC}/LICENSES/LGPL-3.0-only.txt

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	ecm:build
USE_QT=		core dbus gui widgets \
		buildtools:build qmake:build

.include <bsd.port.mk>
