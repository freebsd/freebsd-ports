# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	guikachu
PORTVERSION=	1.5.10
PORTREVISION=	7
PORTEPOCH=	3
CATEGORIES=	devel palm gnome
MASTER_SITES=	http://cactus.rulez.org/projects/guikachu/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Resource editor for PalmOS(tm) systems

LIB_DEPENDS=	libgnomeuimm-2.6.so:x11-toolkits/libgnomeuimm26 \
		libgnomevfsmm-2.6.so:devel/gnome-vfsmm

BROKEN=		fails to build: ustring.h: expected ';' at end of declaration list
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-01-27

USES=		gmake pathfix pkgconfig shared-mime-info desktop-file-utils
USE_GNOME=	gnomeprefix intlhack libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_UPDATE_MIME="no"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	guikachu-form-editor.schemas guikachu-interface.schemas \
		guikachu-mainwin.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|glib/gwin32.h>|glib.h>|g' \
		${WRKSRC}/src/ui.cc

.include <bsd.port.mk>
