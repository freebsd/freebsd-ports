# Created by: Jaosn Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xpad
PORTVERSION=	4.1
PORTREVISION=	3
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/
PKGNAMESUFFIX=	-current

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Virtual note-pad system for your X11 desktop

LICENSE=	GPLv3

CONFLICTS_INSTALL=	xpad-[0-9]*
FETCH_ARGS=	-p
USE_BZIP2=	yes
USE_XORG=	x11 sm
USE_GNOME=	gtk20 gnomehier intltool
USE_PKGCONFIG=	build
INSTALLS_ICONS=	yes
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

#code currently doesn't properly handle --disable-nls (in next upstream milestone)
USE_GETTEXT=	yes

MAN1=		xpad.1

.include <bsd.port.mk>
