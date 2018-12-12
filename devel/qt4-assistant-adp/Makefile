# Created by: lofi@FreeBSD.org
# $FreeBSD$

PORTNAME=	assistant
PORTVERSION=	4.6.3
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	QT
PKGNAMEPREFIX=	qt4-
PKGNAMESUFFIX=	-adp
DISTNAME=	qt-assistant-qassistantclient-library-compat-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt *.adp-compatible documentation browser

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		compiler:c++11-lang qmake qt:4
USE_QT=		moc_build rcc_build uic_build corelib \
		gui network xml doc dbus
QMAKE_ARGS=	QT_CONFIG+="dbus" QT_PRODUCT="OpenSource"

ALL_TARGET=	first

DESCR=		${.CURDIR:H:H}/devel/qt4/pkg-descr

WRKSRC=		${WRKDIR}/${DISTNAME:C/src/version/}

PLIST_FILES=	bin/assistant_adp

pre-configure:
	${REINPLACE_CMD} -e 's|$$$$\[QT_INSTALL_BINS]|${PREFIX}/bin|g' \
		${WRKSRC}/compat.pro

.include <bsd.port.mk>
