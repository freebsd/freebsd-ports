# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/deskutils/nautilus-locked-folder/Makefile,v 1.12 2009/11/28 05:58:59 mezz Exp $

PORTNAME=	nautilus-locked-folder
PORTVERSION=	1.0.0
PORTREVISION=	11
CATEGORIES=	deskutils security
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Nautilus plugin that allows you to encrypt the contents of a folder

DEPRECATED=	nautilus will be updated to the 3.x version which is not compatible with 2.x
EXPIRATION_DATE=2014-04-10

USES=		pkgconfig
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_GNOME=	nautilus2 eel2 libgnomeui
CONFIGURE_ENV=	LIBS="-lssl"
PKGCONFIGS=	gtk+-2.0 libglade-2.0 libnautilus-extension libgnomeui-2.0
# XXX: if was LDFLASG="..." Since variable is spelled incorrect,
# this may be not needed at all
LDFLAGS+=	-L${LOCALBASE}/lib `pkg-config --libs ${PKGCONFIGS}`
CPPFLAGS+=	-I${LOCALBASE}/include `pkg-config --cflags ${PKGCONFIGS}`
PLIST_FILES=	lib/nautilus/extensions-2.0/libnautilus-locked-folder.a \
		lib/nautilus/extensions-2.0/libnautilus-locked-folder.la \
		lib/nautilus/extensions-2.0/libnautilus-locked-folder.so

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/icons/hicolor/32x32/stock/data/|${LOCALBASE}/share/icons/hicolor/32x32/stock/data/|' \
		${WRKSRC}/src/lockedfolder-extension.c
	@${REINPLACE_CMD} -e 's|gladedir)"\\" \\|gladedir)"\\"|g ; \
		s|.*-Werror||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
