PORTNAME=	wmmp
DISTVERSION=	0.12.6
PORTREVISION=	1
CATEGORIES=	audio windowmaker
MASTER_SITES=	https://codeberg.org/beastieboy/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	beastieboy@beastieboy.net
COMMENT=	Dockable musicpd client applet for Window Maker
WWW=		https://codeberg.org/beastieboy/wmmp

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake xorg
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_XORG=	xpm x11 xext

PLIST_FILES=	bin/WMmp \
		share/man/man1/WMmp.1.gz

post-patch:
	${REINPLACE_CMD} -e 's|/man/man1|/share/man/man1|g' \
		${PATCH_WRKSRC}/CMakeLists.txt

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/WMmp

.include <bsd.port.mk>
