# $FreeBSD$

PORTNAME=	crystality
PORTVERSION=	0.92
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	http://ftp.ussg.iu.edu/FreeBSD/distfiles/ \
		http://T32.TecNik93.com/FreeBSD/others_ports/xmms-crystality/sources/
PKGNAMEPREFIX=	xmms-
DISTNAME=	${PORTNAME}-plugin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Realtime XMMS plugin for remastering mp3 sound

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms

USE_GNOME=	imlib
NO_STAGE=	yes
USE_LDCONFIG=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/crystality-stdio ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/libcrystality.so \
		${PREFIX}/lib/xmms/Effect

.include <bsd.port.mk>
