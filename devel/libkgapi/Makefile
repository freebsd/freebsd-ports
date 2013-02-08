# $FreeBSD$

PORTNAME=	libkgapi
PORTVERSION=	0.4.4
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/libkgapi/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE-based library for accessing various Google services

LICENSE=	GPLv2

LIB_DEPENDS=	qjson.0:${PORTSDIR}/devel/qjson

CONFLICTS=	akonadi-google-0.*

MAKE_JOBS_SAFE=	yes
USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	automoc4 kdelibs kdeprefix kdehier pimlibs
USE_LDCONFIG=	yes
USE_QT4=	corelib network webkit xml \
		qmake_build moc_build rcc_build uic_build

pre-configure:
	${REINPLACE_CMD} -e '/pkgconfig/ s/$${LIB_INSTALL_DIR}/libdata/' \
		${WRKSRC}/libkgapi/CMakeLists.txt

.include <bsd.port.mk>
