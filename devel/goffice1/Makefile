# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/goffice1/Makefile,v 1.1 2007/07/23 21:36:19 mezz Exp $

PORTNAME=	goffice
PORTVERSION=	0.2.2
PORTREVISION=	10
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GLib/GTK+ set of document centric objects and utilities

NO_LATEST_LINK=	yes

USE_BZIP2=	yes
USE_GMAKE=	yes
USES=		pathfix
USE_GNOME=	gnomeprefix intlhack libgnomeprint libglade2 \
		libgsf_gnome ltverhack
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/goffice/utils/go-math.h \
		${WRKSRC}/goffice/utils/go-regression.h \
		${WRKSRC}/goffice/utils/go-regression.c \
		${WRKSRC}/goffice/utils/go-regression.c \
		${WRKSRC}/goffice/app/goffice-app.h \
		${WRKSRC}/goffice/ms-compat/god-drawing-ms.c \
		${WRKSRC}/goffice/ms-compat/go-ms-parser.c

.include <bsd.port.mk>
