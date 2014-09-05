# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	guikachu
PORTVERSION=	1.5.10
PORTREVISION=	6
PORTEPOCH=	3
CATEGORIES=	devel palm gnome
MASTER_SITES=	http://cactus.rulez.org/projects/guikachu/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Resource editor for PalmOS(tm) systems

LIB_DEPENDS=	libgnomeuimm-2.6.so:${PORTSDIR}/x11-toolkits/libgnomeuimm26 \
		libgnomevfsmm-2.6.so:${PORTSDIR}/devel/gnome-vfsmm

USES=		gmake pkgconfig shared-mime-info desktop-file-utils
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	guikachu-form-editor.schemas guikachu-interface.schemas \
		guikachu-mainwin.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|glib/gwin32.h>|glib.h>|g' \
		${WRKSRC}/src/ui.cc

.include <bsd.port.mk>
