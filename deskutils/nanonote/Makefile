PORTNAME=	nanonote
DISTVERSION=	1.5.0
CATEGORIES=	deskutils
MASTER_SITES=	https://github.com/agateau/${PORTNAME}/releases/download/${DISTVERSION}/

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Minimalist note taking application
WWW=		https://github.com/agateau/nanonote

LICENSE=	BSD3CLAUSECLEAR
LICENSE_NAME=	BSD 3-Clause Clear License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cmake gl kde:6 qt:6 tar:bz2
USE_GL=		opengl
USE_KDE=	ecm:build
USE_QT=		base tools:build

.include <bsd.port.mk>
