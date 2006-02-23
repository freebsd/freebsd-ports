# New ports collection makefile for:	atk
# Date Created:				14 May 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/accessibility/atk/Makefile,v 1.56 2005/09/05 21:13:50 marcus Exp $
#

PORTNAME=	atk
PORTVERSION=	1.10.3
PORTREVISION=	1
CATEGORIES=	accessibility devel
MASTER_SITES=	${MASTER_SITE_GNOME} \
		ftp://ftp.gtk.org/pub/gtk/v2.6/
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.10
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME accessibility toolkit (ATK)

USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomehack glib20 ltverhack
CONFIGURE_ARGS=	--enable-static \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s/tests//" \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
