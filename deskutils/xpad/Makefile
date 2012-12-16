# Created by:	Guillaume Paquet <amyfoub@gmail.com>
# $FreeBSD$

PORTNAME=	xpad
PORTVERSION=	3.1
PORTREVISION=	7
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpad.net/xpad/stable/${PORTVERSION}/+download/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Virtual note-pad system for your X11 desktop

LICENSE=	GPLv3

CONFLICTS_INSTALL=	xpad-current-[0-9]*

FETCH_ARGS=	"-pRr"
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	x11 sm
USE_GNOME=	gtk20 gnomehier intltool
USE_PKGCONFIG=	build
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_GETTEXT=	yes

MAN1=		xpad.1

.include <bsd.port.mk>
