# New ports collection makefile for:	libnotify
# Date created:				2005-08-06
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	libnotify
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	http://www.galago-project.org/files/releases/source/libnotify/

MAINTAINER=	andreas@syndrom23.de
COMMENT=	A library for desktop notifications

LIB_DEPENDS=	dbus-1.2:${PORTSDIR}/devel/dbus \
		popt.0:${PORTSDIR}/devel/popt

USE_GNOME=	gnomehack gnometarget intlhack glib20 gtk20
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|tests||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
