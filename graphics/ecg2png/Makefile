# New ports collection makefile for:	ecg2png
# Date created:				Sun 2 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	ecg2png
PORTVERSION=	0.30
CATEGORIES=	graphics
MASTER_SITES=	ftp://www.cardiothink.com/pub/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gd.1:${PORTSDIR}/graphics/gd

USE_QT2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -I${X11BASE}/include/qt2 -I${LOCALBASE}/include/gd" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
USE_GMAKE=	yes

.include <bsd.port.mk>
