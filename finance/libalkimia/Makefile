# $FreeBSD$

PORTNAME=	libalkimia
PORTVERSION=	4.3.2
PORTREVISION=	4
CATEGORIES=	finance kde
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/
DISTNAME=	137323-${PORTNAME}-${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE4 financial data handling library

LICENSE=	LGPL21

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp

USES=		cmake pkgconfig tar:bzip2
USE_KDE4=	automoc4 kdeprefix kdelibs
USE_QT4=	qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|pkgconfig|../libdata/pkgconfig|' \
		${WRKSRC}/${PORTNAME}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|KDE4_LIB_DIR|LIB_INSTALL_DIR|g' \
		${WRKSRC}/${PORTNAME}/libalkimia.pc.in

.include <bsd.port.mk>
