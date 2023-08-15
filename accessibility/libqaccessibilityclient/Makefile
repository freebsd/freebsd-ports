PORTNAME=	libqaccessibilityclient
DISTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	accessibility kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Helper to make writing accessibility tools easier
WWW=		https://github.com/kde/libqaccessibilityclient

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	ecm:build
USE_QT=		core dbus gui widgets \
		buildtools:build qmake:build

.include <bsd.port.mk>
