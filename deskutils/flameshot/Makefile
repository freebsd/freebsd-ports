PORTNAME=	flameshot
PORTVERSION=	12.1.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	deskutils wayland

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Powerful yet simple to use screenshot software
WWW=		https://flameshot.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang desktop-file-utils gl qmake qt:5

USE_GITHUB=	yes
GH_ACCOUNT=	flameshot-org
USE_GL=		gl
USE_QT=		core dbus gui linguist network svg widgets buildtools:build

CMAKE_INSTALL_PREFIX=	${STAGEDIR}/${PREFIX}

post-patch:
	        @${REINPLACE_CMD} -e 's,$${CMAKE_INSTALL_FULL_BINDIR},${LOCALBASE}/bin,1' \
			-e 's,^\(Exec=\)@LAUNCHER_EXECUTABLE@,\1${LOCALBASE}/bin/${PORTNAME},1' \
	                ${WRKSRC}/data/dbus/org.flameshot.Flameshot.service.in \
	                ${WRKSRC}/data/desktopEntry/package/org.flameshot.Flameshot.desktop

.include <bsd.port.mk>
