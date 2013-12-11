# Created by: hrkfrd@googlemail.com
# $FreeBSD$

PORTNAME=	mpdas
PORTVERSION=	0.3.0
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://50hz.ws/mpdas/

MAINTAINER=	hrkfdn@gmail.com
COMMENT=	MPD AudioScrobbler written in C++ supporting the latest protocol

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libmpd.so:${PORTSDIR}/audio/libmpd

USES=		pkgconfig
NO_STAGE=	yes
USE_BZIP2=	yes

USE_RC_SUBR=	mpdas

SUB_FILES=	pkg-message

PLIST_FILES=	bin/mpdas

MAN1=		mpdas.1
MANCOMPRESSED=	no

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local#${PREFIX}#g; \
		s#MANPREFIX#MAN_PREFIX#g' ${WRKSRC}/Makefile

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
