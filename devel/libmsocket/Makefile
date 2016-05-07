# Created by: Matt Harris <mattdharris@users.sourceforge.net>
# $FreeBSD$

PORTNAME=	libmsocket
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	SF/kageki/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Socket abstraction library for C programmers

LIB_DEPENDS=	libevent.so:devel/libevent2

OPTIONS_DEFINE=	DEBUG

USES=		tar:bzip2 desthack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-throttling \
		--with-libevent=${LOCALBASE}

PLIST_FILES=	lib/libmsocket.so \
		lib/libmsocket.so.0.1 \
		lib/libmsocket.a \
		include/msocket.h \
		include/msocketutils.h

CFLAGS_aarch64+=-fPIC -DPIC
CFLAGS_amd64+=	-fPIC -DPIC
CFLAGS_iad64+=	-fPIC -DPIC

DEBUG_CONFIGURE_ON=	--enable-debug

post-patch:
	${REINPLACE_CMD} 's,  withval=$$with_libevent; cf_enable_libevent=$$enableval,   withval=$$with_libevent; cf_enable_libevent=$$with_libevent,' \
		${WRKSRC}/configure

post-install:
	${LN} -sf libmsocket.so.0.1 ${STAGEDIR}${PREFIX}/lib/libmsocket.so

.include <bsd.port.mk>
