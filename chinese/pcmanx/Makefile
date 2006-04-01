# New ports collection makefile for:   pcmanx
# Date created:                2005/07/16
# Whom:                        chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pcmanx
PORTVERSION=	0.3.3
PORTREVISION=	3
CATEGORIES=	chinese net gnome
MASTER_SITES=	http://pcmanx.csie.net/release/
DISTNAME=	pcmanx-pure-gtk2-${PORTVERSION}

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	BBS client using GTK+ 2.x

USE_GNOME=	gtk20 intlhack
USE_GCC=	3.3+
USE_ICONV=	yes
GNU_CONFIGURE=	yes
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
