# New ports collection makefile for:	ecg2png
# Date created:				Sun 2 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	ecg2png
PORTVERSION=	0.30
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.cardiothink.com/downloads/ecg2png/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"Converts scanned 12-lead electrocardiograms into PNGs"

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/ecg2png
USE_REINPLACE=	yes
USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
QTCPPFLAGS+=	${CFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include

pre-patch:
	@${REINPLACE_CMD} -e 's|-lqt$$|-lqt-mt ${PTHREAD_LIBS}|g' ${WRKSRC}/ecg2png/Makefile.in
	@${FIND} ${WRKSRC} -name '*.cpp' | ${XARGS} ${REINPLACE_CMD} -e \
		's|#include <qimageio.h>||g'
	@${CHMOD} ${BINMODE} ${WRKSRC}/missing

.include <bsd.port.mk>
