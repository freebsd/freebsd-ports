# New ports collection makefile for:	nautilus-locked-folder
# Date created:		2005-09-17
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/deskutils/nautilus-locked-folder/Makefile,v 1.2 2005/09/20 09:31:50 ahze Exp $
#

PORTNAME=	nautilus-locked-folder
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	deskutils security
MASTER_SITES=	http://www.ids.org.au/~jam6/locked-folders/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Nautilus plugin that allows you to encrypt the contents of a folder

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	nautilus2
PKGCONFIGS=	gtk+-2.0 libglade-2.0 libnautilus-extension libgnomeui-2.0
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include `pkg-config --cflags ${PKGCONFIGS}`" \
		LDFLASG="-L${LOCALBASE}/lib -L${X11BASE}/lib `pkg-config --libs ${PKGCONFIGS}`" \
		LIBS="-lssl"
PLIST_FILES=	lib/nautilus/extensions-1.0/libnautilus-locked-folder.a \
		lib/nautilus/extensions-1.0/libnautilus-locked-folder.la \
		lib/nautilus/extensions-1.0/libnautilus-locked-folder.so

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/icons/hicolor/32x32/stock/data/|${X11BASE}/share/icons/hicolor/32x32/stock/data/|' \
		${WRKSRC}/src/lockedfolder-extension.c
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN="Does not build"
.endif

.include <bsd.port.post.mk>
