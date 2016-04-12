# Created by: Remington Lang <MrL0Lz@gmail.com>
# $FreeBSD$

PORTNAME=	superswitcher
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alt-Tab replacement

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib

USES=		gmake pkgconfig
USE_GNOME=	gconf2 intltool libwnck
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/superswitcher \
		share/dbus-1/services/superswitcher.SuperSwitcher.service

post-patch:
	@${REINPLACE_CMD} -e \
		's/x11//g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/_DISABLE_DEPRECATED/d' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/src/dbus-object.h ${WRKSRC}/src/forward_declarations.h

post-install:
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/locale

.include <bsd.port.mk>
