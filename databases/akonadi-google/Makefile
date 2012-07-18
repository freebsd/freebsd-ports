# New ports collection Makefile for:	akonadi-google
# Date created:				10 April 2012
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	akonadi-google
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	databases kde
MASTER_SITES=	http://www.progdan.cz/wp-content/uploads/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Akonadi resources for accessing Google services

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	qjson.0:${PORTSDIR}/devel/qjson
BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt

USE_KDE4=	kdehier kdelibs kdeprefix pimlibs automoc4
USE_QT4=	dbus gui network webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

pre-configure:
	${REINPLACE_CMD} -e '/pkgconfig/ s/$${LIB_INSTALL_DIR}/libdata/' \
		${WRKSRC}/libkgoogle/CMakeLists.txt

.include <bsd.port.mk>
