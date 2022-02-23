PORTNAME=	kseexpr
DISTVERSION=	4.0.4.0
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION:R}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Embeddable expression engine for Krita

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

CONFLICTS_INSTALL=	seexpr

USES=		bison cmake kde:5 qt:5
USE_KDE=	ecm i18n
USE_QT=		core gui widgets buildtools_build linguisttools_build qmake_build

.include <bsd.port.mk>
