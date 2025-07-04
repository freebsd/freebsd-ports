PORTNAME=	birdtray
PORTVERSION=	1.11.4
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils mail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	System tray new mail notification for Thunderbird
WWW=		https://github.com/gyunaev/birdtray

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake compiler:c++11-lib gettext kde:5 localbase qt:5 tar:xz \
		xorg
USE_XORG=	x11
USE_KDE=	i18n
USE_QT=		core gui network svg widgets x11extras buildtools:build \
		linguisttools:build qmake:build
USE_GITHUB=	yes
GH_ACCOUNT=	gyunaev

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/src/utils.cpp

.include <bsd.port.mk>
