PORTNAME=	xdg-utils
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
CATEGORIES=	devel

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Tools to allow all applications to integrate with the free desktop
WWW=		https://www.freedesktop.org/wiki/Software/xdg-utils/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	xmlto:textproc/xmlto
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme

USES=		cpe gmake
CPE_VENDOR=	freedesktop
USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	xdg

GNU_CONFIGURE=	yes

NO_ARCH=	yes

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_RUN_DEPENDS=xprop:x11/xprop \
		xset:x11/xset

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/scripts/xdg-*.in

.include <bsd.port.mk>
