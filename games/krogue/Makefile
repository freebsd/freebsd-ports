# New ports collection makefile for:	krogue
# Date created:		19 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	krogue
PORTVERSION=	0.9.6.1
CATEGORIES=	games
MASTER_SITES=	http://ksi.ii.uj.edu.pl/krogue/dl/
DISTNAME=	${PORTNAME}-0.9.6pl1
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11

USE_QT=		yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	QTDIR="${X11BASE}" KDEDIR="${LOCALBASE}"
CONFIGURE_ARGS=	--with-qt-includes=${X11BASE}/include/X11/qt

.include <bsd.port.mk>
