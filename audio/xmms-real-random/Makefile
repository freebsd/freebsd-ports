# New ports collection makefile for:	xmms-real-random
# Date created:				03.10.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	xmms-real-random
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://kingleo.home.pages.at/development/stuff/
DISTNAME=	real_random-${PORTVERSION}

MAINTAINER=	q@uni.de
COMMENT=	REAL shuffle mode for xmms

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_X_PREFIX=	yes

CONFIGURE_ENV=	CFLAGS='${CFLAGS}'

post-patch:
.for Makefile in Makefile.am Makefile.in
	@${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/' ${WRKSRC}/${Makefile}
.endfor

.include <bsd.port.mk>
