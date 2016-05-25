# $FreeBSD$

PORTNAME=	libalkimia
PORTVERSION=	5.0.0
PORTREVISION=	1
CATEGORIES=	finance kde
MASTER_SITES=	KDE/stable/alkimia/${PORTVERSION}/src

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE4 financial data handling library

LICENSE=	LGPL21

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		cmake:outsource pathfix tar:xz
USE_KDE4=	automoc4 kdelibs
USE_QT4=	qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|KDE4_LIB_DIR|LIB_INSTALL_DIR|g' \
		${WRKSRC}/${PORTNAME}/libalkimia.pc.in

.include <bsd.port.mk>
