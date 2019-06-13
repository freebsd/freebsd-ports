# $FreeBSD$

PORTNAME=	libqaccessibilityclient
DISTVERSION=	0.4.1
CATEGORIES=	accessibility kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Helper to make writing accessibility tools easier

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang kde:5 qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		core dbus gui widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
