# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	guikachu
PORTVERSION=	1.5.10
PORTREVISION=	8
PORTEPOCH=	3
CATEGORIES=	devel palm gnome
MASTER_SITES=	http://cactus.rulez.org/projects/guikachu/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Resource editor for PalmOS systems

BROKEN=		fails to build
DEPRECATED=	Broken for more than 9 months
EXPIRATION_DATE=	2018-03-25

LIB_DEPENDS=	libgnomeuimm-2.6.so:x11-toolkits/libgnomeuimm26 \
		libgnomevfsmm-2.6.so:devel/gnome-vfsmm

USES=		compiler:c++11-lang gmake pathfix pkgconfig \
		shared-mime-info desktop-file-utils
USE_CXXSTD=	c++11
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
