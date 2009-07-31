# New ports collection makefile for:	xmms-crystality
# Date created:				Fri Aug 17 20:34:09 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	crystality
PORTVERSION=	0.92
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://ftp.ussg.iu.edu/FreeBSD/distfiles/ \
		http://T32.TecNik93.com/FreeBSD/others_ports/xmms-crystality/sources/
PKGNAMEPREFIX=	xmms-
DISTNAME=	${PORTNAME}-plugin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Realtime XMMS plugin for remastering mp3 sound

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_GNOME=	imlib
USE_LDCONFIG=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/crystality-stdio ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/libcrystality.so \
		${PREFIX}/lib/xmms/Effect

.include <bsd.port.mk>
