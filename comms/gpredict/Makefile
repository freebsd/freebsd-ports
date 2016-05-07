# Created by: Matt Dawson <matt@mattsnetwork.co.uk>
# $FreeBSD$

PORTNAME=	gpredict
PORTVERSION=	1.3
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}/Gpredict/${PORTVERSION}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio satellite tracking and prediction

LICENSE=	GPLv2+

LIB_DEPENDS=	libhamlib.so:comms/hamlib \
		libcurl.so:ftp/curl \
		libgoocanvas.so:graphics/goocanvas

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		gettext gmake pkgconfig
USE_GNOME=	gtk20 intltool

post-patch:
	@${REINPLACE_CMD} -e \
		'/^Icon/s|=.*|=${PREFIX}/share/pixmaps/gpredict-icon.png|' \
		${WRKSRC}/data/desktop/gpredict.desktop.in

.include <bsd.port.mk>
