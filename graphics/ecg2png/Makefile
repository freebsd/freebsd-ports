# New ports collection makefile for:	ecg2png
# Date created:				Sun 2 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	ecg2png
PORTVERSION=	0.30
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.cardiothink.com/downloads/ecg2png/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_QT_VER=	2
QTCPPFLAGS+=	-I${LOCALBASE}/include/gd
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
CONFIGURE_ARGS=	--x-includes=${X11BASE}/include --x-libraries=${X11BASE}/lib

.include <bsd.port.mk>
