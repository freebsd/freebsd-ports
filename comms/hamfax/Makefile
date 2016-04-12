# Created by: Carl Makin <carl@stagecraft.cx>
# $FreeBSD$

PORTNAME=	hamfax
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	comms audio hamradio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	carl@stagecraft.cx
COMMENT=	QT application for sending and receiving facsimiles over radio

LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile

USE_QT4=	gui moc_build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
USES=		gmake pkgconfig tar:bzip2

.include <bsd.port.mk>
