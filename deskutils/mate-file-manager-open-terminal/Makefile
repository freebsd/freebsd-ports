# Created by: Nicole Reid <root@cooltrainer.org>
# $FreeBSD$

PORTNAME=	mate-file-manager-open-terminal
PORTVERSION=	1.6.0
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Caja extension which allows you to open a terminal

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_MATE=	autogen caja common:build desktop intlhack
USE_GNOME=	glib20 gnomehier
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env \
		autoheader:env
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PATHFIX_MAKEFILEIN=	Makefile.*

GLIB_SCHEMAS=	org.mate.apps.caja-open-terminal.gschema.xml

.include <bsd.port.mk>
