PORTNAME=	scrot
DISTVERSION=	2.0.0
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	SCReenshOT - command line screen capture utility
WWW=		https://github.com/resurrecting-open-source-projects/scrot

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive
LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USES=		autoreconf pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	resurrecting-open-source-projects
GNU_CONFIGURE=	yes
USE_XORG=	x11 xfixes xcomposite xrandr

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
