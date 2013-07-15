# Created by: Matt Dawson <matt@mattsnetwork.co.uk>
# $FreeBSD$

PORTNAME=	gpredict
PORTVERSION=	1.3
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}/Gpredict/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Amateur Radio satellite tracking and prediction

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	hamlib:${PORTSDIR}/comms/hamlib \
		curl:${PORTSDIR}/ftp/curl \
		goocanvas:${PORTSDIR}/graphics/goocanvas

USES=		gettext pathfix
USE_GNOME=	gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		gpredict.1

post-patch:
	@${REINPLACE_CMD} -e \
		'/^Icon/s|=.*|=${PREFIX}/share/pixmaps/gpredict-icon.png|' \
		${WRKSRC}/data/desktop/gpredict.desktop.in

.include <bsd.port.mk>
