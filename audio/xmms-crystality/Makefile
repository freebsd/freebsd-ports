# New ports collection makefile for:	xmms-crystality
# Date created:				Fri Aug 17 20:34:09 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	crystality
PORTVERSION=	0.92
CATEGORIES=	audio
MASTER_SITES=	http://fanthom.math.put.poznan.pl/~gyver/crystality/
PKGNAMEPREFIX=	xmms-
DISTNAME=	${PORTNAME}-plugin-${PORTVERSION}

MAINTAINER=	pat@FreeBSD.org

LIB_DEPENDS=	xmms.3:${PORTSDIR}/audio/xmms

USE_X_PREFIX=	yes
USE_GTK=	yes
USE_IMLIB=	yes
INSTALLS_SHLIB=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/crystality-stdio ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/libcrystality.so \
		${PREFIX}/lib/xmms/Effect

.include <bsd.port.mk>
