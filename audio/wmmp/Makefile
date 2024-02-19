PORTNAME=	wmmp
PORTVERSION=	0.12.6
PORTREVISION=	1
CATEGORIES=	audio windowmaker

MAINTAINER=	nicolasherry@gmail.com
COMMENT=	Dockable musicpd client applet for Window Maker
WWW=		https://github.com/yogsothoth/wmmp

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake xorg
USE_GITHUB=	yes
GH_ACCOUNT=	yogsothoth
USE_XORG=	xpm x11 xext

PLIST_FILES=	bin/WMmp share/man/man1/WMmp.1.gz

post-patch:
	${REINPLACE_CMD} -e 's|DESTINATION $${CMAKE_INSTALL_PREFIX}/man/man1|DESTINATION $${CMAKE_INSTALL_PREFIX}/share/man/man1|' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/WMmp

.include <bsd.port.mk>
