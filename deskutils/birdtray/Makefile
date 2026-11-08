PORTNAME=	birdtray
PORTVERSION=	1.12.g20260803
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils mail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System tray new mail notification for Thunderbird
WWW=		https://github.com/gyunaev/birdtray

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++11-lib gettext localbase:ldflags qt:6 tar:xz \
		xorg
USE_XORG=	x11
USE_QT=		base svg tools:build
USE_GITHUB=	yes
GH_ACCOUNT=	gyunaev
GH_TAGNAME=	bcceec6a1a56fa7acd19e1b6a93f430b5a566537

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/src/utils.cpp

.include <bsd.port.mk>
