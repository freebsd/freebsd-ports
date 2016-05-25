# $FreeBSD$

PORTNAME=	libkgapi
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/libkgapi/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE-based library for accessing various Google services

LICENSE=	GPLv2

LIB_DEPENDS=	libqjson.so:devel/qjson

USES=		cmake:outsource tar:bzip2
USE_KDE4=	automoc4 kdelibs pimlibs
USE_LDCONFIG=	yes
USE_QT4=	corelib network webkit xml \
		qmake_build moc_build rcc_build uic_build

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

pre-configure:
	${REINPLACE_CMD} -e '/pkgconfig/ s/$${LIB_INSTALL_DIR}/libdata/' \
		${WRKSRC}/libkgapi*/CMakeLists.txt

.include <bsd.port.mk>
