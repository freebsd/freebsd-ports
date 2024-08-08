PORTNAME=	nanonote
DISTVERSION=	1.4.1
CATEGORIES=	deskutils
MASTER_SITES=	https://github.com/agateau/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Minimalist note taking application
WWW=		https://github.com/agateau/nanonote

LICENSE=	BSD3CLAUSECLEAR
LICENSE_NAME=	BSD 3-Clause Clear License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake kde:5 qt:5 tar:bz2

USE_KDE=	ecm:build
USE_QT=		buildtools:build qmake:build \
		core gui linguisttools network testlib widgets

.include <bsd.port.mk>
