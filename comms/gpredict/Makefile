# Created by: Matt Dawson <matt@mattsnetwork.co.uk>
# $FreeBSD$

PORTNAME=	gpredict
PORTVERSION=	1.3
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}/Gpredict/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Amateur Radio satellite tracking and prediction

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libhamlib.so:${PORTSDIR}/comms/hamlib \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libgoocanvas.so:${PORTSDIR}/graphics/goocanvas

USES=		gettext pathfix gmake pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		'/^Icon/s|=.*|=${PREFIX}/share/pixmaps/gpredict-icon.png|' \
		${WRKSRC}/data/desktop/gpredict.desktop.in

.include <bsd.port.mk>
