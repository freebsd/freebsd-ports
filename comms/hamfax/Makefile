# Created by: Carl Makin <carl@stagecraft.cx>
# $FreeBSD$

PORTNAME=	hamfax
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	comms audio hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	carl@stagecraft.cx
COMMENT=	QT application for sending and receiving facsimiles over radio

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile

USE_QT=		gui moc_build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
USES=		gmake pkgconfig qt:4 tar:bzip2

.include <bsd.port.mk>
