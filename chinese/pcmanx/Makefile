# New ports collection makefile for:   pcmanx
# Date created:                2005/07/16
# Whom:                        chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pcmanx
PORTVERSION=	0.2.6
CATEGORIES=	chinese net
MASTER_SITES=	http://pcmanx.csie.net/release/ \
		http://bbs.ilc.edu.tw/~chinsan/pcmanx/
DISTNAME=	pcmanx-pure-gtk2-${PORTVERSION}

# Maintainership available: drop me a line if interested :p
MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	PCManX is a BBS client using GTK+ 2.x

USE_GNOME=	gtk20 intlhack
USE_LIBTOOL_VER=15
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
