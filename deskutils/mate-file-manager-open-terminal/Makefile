# Created by: Nicole Reid <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	mate-file-manager-open-terminal
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Caja extension which allows you to open a terminal

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_MATE=	autogen caja common:build desktop intlhack
USE_GNOME=	glib20 gnomehier
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtoolize:env \
		autoheader:env
CONFIGURE_ARGS=	--disable-static
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PATHFIX_MAKEFILEIN=	Makefile.*
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.caja-open-terminal.gschema.xml

.include <bsd.port.mk>
