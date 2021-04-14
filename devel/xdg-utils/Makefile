# Created by: Michael Johnson <ahze@FreeBSD.org>

PORTNAME=	xdg-utils
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://portland.freedesktop.org/download/

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Tools to allow all applications to integrate with the free desktop

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	minixmlto:textproc/minixmlto
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme

USES=		gmake

CONFIGURE_ENV=	XMLTO=${LOCALBASE}/bin/minixmlto
GNU_CONFIGURE=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11
X11_RUN_DEPENDS=xprop:x11/xprop \
		xset:x11/xset

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/scripts/xdg-*

.include <bsd.port.mk>
