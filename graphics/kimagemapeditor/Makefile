# New ports collection makefile for:	kimagemapeditor
# Date created:				19 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$

PORTNAME=	kimagemapeditor
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	graphics kde
MASTER_SITES=	http://www.brueffer.de/distfiles/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	KDE-based editor for HTML image maps

USE_BZIP2=	yes
USE_KDELIBS_VER=	3
USE_GMAKE=	yes
USE_LIBTOOL_VER=13
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}" 

pre-configure:
	${REINPLACE_CMD} -e 's|-O2||g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
