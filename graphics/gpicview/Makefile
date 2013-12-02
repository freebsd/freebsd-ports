# Created by: Janos Mohacsi <janos.mohacsi@bsd.hu>
# $FreeBSD$

PORTNAME=	gpicview
PORTVERSION=	0.2.4
CATEGORIES=	graphics
MASTER_SITES=	SF/lxde/GPicView%20%28image%20Viewer%29/GpicView%20${PORTVERSION}/

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Simple and fast image viewer for X11

LICENSE=	GPLv2

USES=		desktop-file-utils gmake pkgconfig
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
