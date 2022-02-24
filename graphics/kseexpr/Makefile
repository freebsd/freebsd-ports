PORTNAME=	kseexpr
DISTVERSION=	4.0.4.0
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION:R}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Embeddable expression engine for Krita

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		bison cmake kde:5 qt:5
USE_KDE=	ecm i18n
USE_LDCONFIG=	yes
USE_QT=		core gui widgets buildtools_build linguisttools_build qmake_build

CONFLICTS_INSTALL=	seexpr

.include <bsd.port.mk>
