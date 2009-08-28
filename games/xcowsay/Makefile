# New ports collection makefile for:	xcowsay
# Date created:		2008/09/07
# Whom:			chinsan
#
# $FreeBSD$
#

PORTNAME=	xcowsay
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	http://www.nickg.me.uk/files/ LOCAL/chinsan/games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical configurable talking cow

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 gdkpixbuf intlhack
USE_GMAKE=	yes
USE_ICONV=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN6=		xcowsay.6

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
