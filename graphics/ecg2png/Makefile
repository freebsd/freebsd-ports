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

MAINTAINER=	kde@freebsd.org

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_REINPLACE=	yes
USE_QT_VER=	2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
QTCPPFLAGS+=	-I${LOCALBASE}/include/gd

pre-patch:
	@${REINPLACE_CMD} -e 's|-lqt$$|-l${QTNAME}|g' ${WRKSRC}/ecg2png/Makefile.in
	@${FIND} ${WRKSRC} -name '*.cpp' | ${XARGS} ${REINPLACE_CMD} -e \
		's|#include <qimageio.h>||g'
	@${CHMOD} ${BINMODE} ${WRKSRC}/missing

.include <bsd.port.mk>
