PORTNAME=	futuresql
DISTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	databases kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Non-blocking database framework for Qt
WWW=		https://api.kde.org/futuresql/html/index.html

USES=		cmake kde:5 qt:5 tar:xz

USE_KDE=	ecm:build
USE_QT=		core sql \
		buildtools:build qmake:build

.include <bsd.port.mk>
