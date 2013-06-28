# $FreeBSD$

PORTNAME=	xdg-user-dirs
PORTVERSION=	0.15
CATEGORIES=	devel
MASTER_SITES=	http://user-dirs.freedesktop.org/releases/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Tool to help manage personal user directories

GNU_CONFIGURE=	yes
USES=		gettext iconv
USE_GMAKE=	yes
USE_GNOME=	libxslt:build
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

MAN1=		xdg-user-dir.1 xdg-user-dirs-update.1
MAN5=		user-dirs.conf.5 user-dirs.defaults.5 user-dirs.dirs.5

.include <bsd.port.mk>
