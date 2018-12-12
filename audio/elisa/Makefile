# $FreeBSD$

PORTNAME=	elisa
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	audio kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Audio player with QML and KDE Plasma integration

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++14-lang desktop-file-utils gettext kde:5 \
		pkgconfig qt:5 tar:xz
USE_QT=		buildtools_build qmake_build testlib_build \
		concurrent core dbus declarative gui multimedia network \
		quickcontrols2 sql svg widgets xml
USE_KDE=	auth baloo5 bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons filemetadata i18n itemviews \
		jobwidgets kcmutils kdeclarative kio package service solid \
		widgetsaddons xmlgui

.include <bsd.port.mk>
