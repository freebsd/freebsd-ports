# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/trunk/devel/xdg-utils/Makefile 18656 2013-08-22 09:09:28Z kwm $

PORTNAME=	xdg-utils
PORTVERSION=	1.0.2.${SNAPDATE}
CATEGORIES=	devel
#MASTER_SITES=	http://portland.freedesktop.org/download/
MASTER_SITES=	LOCAL/kwm
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tools to allow all applications to integrate with the free desktop

RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		xprop:${PORTSDIR}/x11/xprop \
		xset:${PORTSDIR}/x11/xset

SNAPDATE=	20130919
USE_XZ=		yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/scripts/xdg-*

.include <bsd.port.mk>
