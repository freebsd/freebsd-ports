# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xdg-utils
PORTVERSION=	1.1.1
CATEGORIES=	devel
MASTER_SITES=	http://portland.freedesktop.org/download/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tools to allow all applications to integrate with the free desktop

BUILD_DEPENDS=	xmlto:${PORTSDIR}/textproc/xmlto
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		xprop:${PORTSDIR}/x11/xprop \
		xset:${PORTSDIR}/x11/xset

USES=		gmake
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/scripts/xdg-*

.include <bsd.port.mk>
