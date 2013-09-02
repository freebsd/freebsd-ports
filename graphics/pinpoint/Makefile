# Created by: lichray@gmail.com
# $FreeBSD$

PORTNAME=	pinpoint
DISTVERSION=	0.1.4
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	GNOME

MAINTAINER=	lichray@gmail.com
COMMENT=	Tool for making hackers do excellent presentations

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	clutter-glx-1.0:${PORTSDIR}/graphics/clutter

USE_XZ=		yes
USE_GL=		gl
USE_GMAKE=	yes
USE_GNOME=	librsvg2
GNU_CONFIGURE=	yes
USES=	pathfix pkgconfig

OPTIONS_DEFINE=	GST
GST_DESC=	Live videos as slide backgrounds

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGST}
LIB_DEPENDS+=	clutter-gst-1.0:${PORTSDIR}/multimedia/clutter-gst
.else
CONFIGURE_ARGS+=	--enable-cluttergst=no
.endif

.include <bsd.port.mk>
