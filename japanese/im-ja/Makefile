# New ports collection makefile for:	im-ja
# Date created:				2003/09/02
# Whom:					Jacques Vidrine <nectar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	im-ja
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	japanese x11-toolkits
MASTER_SITES=	http://im-ja.sourceforge.net/

MAINTAINER=	nectar@FreeBSD.org
COMMENT=	A Japanese input module for GTK2

.if !defined(WITHOUT_CANNA)
LIB_DEPENDS+=	RKC.1:${PORTSDIR}/japanese/Canna
.endif
.if !defined(WITHOUT_WNN)
LIB_DEPENDS+=	wnn.0:${PORTSDIR}/japanese/FreeWnn-lib
.endif

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_GNOME=	gnomeprefix gnomehack gnomepanel
GNU_CONFIGURE=	yes

.if defined(WITHOUT_CANNA)
CONFIGURE_ARGS+=	--disable-canna
.endif
.if defined(WITHOUT_WNN)
CONFIGURE_ARGS+=	--disable-wnn
.endif
LIBS+=		-L${LOCALBASE}/lib -L${X11BASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
CONFIGURE_ENV=	LIBS="${LIBS}" CPPFLAGS="${CPPFLAGS}"

MAN1=		im-ja-conf.1

post-install:
	${X11BASE}/bin/gtk-query-immodules-2.0 > \
	    ${X11BASE}/etc/gtk-2.0/gtk.immodules

.include <bsd.port.mk>
