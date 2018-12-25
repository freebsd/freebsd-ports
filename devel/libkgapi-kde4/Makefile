# $FreeBSD$

PORTNAME=	libkgapi
PORTVERSION=	2.2.0
PORTREVISION=	5
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/libkgapi/${PORTVERSION}/src
PKGNAMESUFFIX=	-kde4
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE-based library for accessing various Google services

LICENSE=	GPLv2

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libqjson.so:devel/qjson@qt4

USES=		cmake kde:4 qt:4 tar:bzip2
USE_KDE=	automoc4 kdelibs pimlibs
USE_LDCONFIG=	yes
USE_QT=		corelib network webkit xml \
		qmake_build moc_build rcc_build uic_build

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

pre-configure:
	${REINPLACE_CMD} -e '/pkgconfig/ s/$${LIB_INSTALL_DIR}/libdata/' \
		${WRKSRC}/libkgapi*/CMakeLists.txt

.include <bsd.port.mk>
