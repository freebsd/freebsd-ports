# New ports collection makefile for:	nautilus-locked-folder
# Date created:		2005-09-17
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/deskutils/nautilus-locked-folder/Makefile,v 1.9 2009/04/07 03:12:16 marcus Exp $
#

PORTNAME=	nautilus-locked-folder
PORTVERSION=	1.0.0
PORTREVISION=	7
CATEGORIES=	deskutils security
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Nautilus plugin that allows you to encrypt the contents of a folder

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_GNOME=	nautilus2 eel2
PKGCONFIGS=	gtk+-2.0 libglade-2.0 libnautilus-extension libgnomeui-2.0
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include `pkg-config --cflags ${PKGCONFIGS}`" \
		LDFLASG="-L${LOCALBASE}/lib `pkg-config --libs ${PKGCONFIGS}`" \
		LIBS="-lssl"
PLIST_FILES=	lib/nautilus/extensions-2.0/libnautilus-locked-folder.a \
		lib/nautilus/extensions-2.0/libnautilus-locked-folder.la \
		lib/nautilus/extensions-2.0/libnautilus-locked-folder.so

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/icons/hicolor/32x32/stock/data/|${LOCALBASE}/share/icons/hicolor/32x32/stock/data/|' \
		${WRKSRC}/src/lockedfolder-extension.c
	@${REINPLACE_CMD} -e 's|gladedir)"\\" \\|gladedir)"\\"|g ; \
		s|.*-Werror||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
