# New ports collection makefile for:	xmms-real-random
# Date created:				03.10.2003
# Whom:					Ulrich Spoerlein <q@uni.de>
#
# $FreeBSD$
#

PORTNAME=	xmms-real-random
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://kingleo.home.pages.at/development/stuff/
DISTNAME=	real_random-${PORTVERSION}

MAINTAINER=	q@galgenberg.net
COMMENT=	REAL shuffle mode for xmms

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_X_PREFIX=	yes

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" CC="${CC}"

PLIST_FILES=	lib/xmms/General/libreal_random.la \
		lib/xmms/General/libreal_random.so

post-patch:
	@${REINPLACE_CMD} -e 's#-lpthread#${PTHREAD_LIBS}#' \
		-e 's#gcc#$${CC}#' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
