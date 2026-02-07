PORTNAME=	kseexpr
DISTVERSION=	4.0.4.0
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION:R}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Embeddable expression engine for Krita
WWW=		https://invent.kde.org/graphics/kseexpr

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		bison cmake kde:5 qt:5
USE_KDE=	i18n \
		ecm:build
USE_LDCONFIG=	yes
USE_QT=		core gui widgets \
		buildtools:build linguisttools:build qmake:build

CONFLICTS_INSTALL=	seexpr

.include <bsd.port.mk>
