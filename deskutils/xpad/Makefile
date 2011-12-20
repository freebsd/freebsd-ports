# New ports collection makefile for:	xpad
# Date created:		6 March 2002
# Whom:			Guillaume Paquet <amyfoub@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xpad
PORTVERSION=	3.1
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	http://launchpad.net/xpad/stable/${PORTVERSION}/+download/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	A virtual note-pad system for your X11 desktop

LICENSE=	GPLv3

CONFLICTS_INSTALL=	xpad-current-[0-9]*

FETCH_ARGS=	"-pRr"
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	x11 sm
USE_GNOME=	pkgconfig gtk20 gnomehier intltool
GNU_CONFIGURE=	yes
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		xpad.1

.include <bsd.port.mk>
