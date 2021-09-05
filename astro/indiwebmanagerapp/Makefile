PORTNAME=	indiwebmanagerapp
DISTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	astro

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Graphical program to manage an INDI WebManager

LICENSE=	GPLv2

RUN_DEPENDS=	indiserver:devel/indi \
		${PYTHON_PKGNAMEPREFIX}indiweb>0:astro/py-indiweb@${PY_FLAVOR}

USES=		cmake iconv gettext kde:5 ninja qt:5 pkgconfig python:3.5+
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons doctools i18n kio itemviews jobwidgets service \
		solid widgetsaddons windowsystem xmlgui
USE_QT=		buildtools concurrent core dbus gui qmake_build network widgets \
		xml
USE_GITHUB=	yes
GH_ACCOUNT=	rlancaste
GH_PROJECT=	INDIWebManagerApp

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' -e \
		's|python3|${PYTHON_VERSION}|g' ${WRKSRC}/src/mainwindow.cpp
	${REINPLACE_CMD} -e 's|On Linux|On Linux\/FreeBSD|g' \
		${WRKSRC}/src/opsconfiguration.cpp

.include <bsd.port.mk>
