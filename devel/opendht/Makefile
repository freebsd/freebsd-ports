# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	opendht
PORTVERSION=	0.5.2
CATEGORIES=	devel net

MAINTAINER=	yuri@rawbw.com
COMMENT=	Lightweight Distributed Hash Table implementation

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmsgpackc.so:devel/msgpack \
		libnettle.so:security/nettle \
		libgnutls.so:security/gnutls \
		libreadline.so:devel/readline

USE_GITHUB=	yes
GH_ACCOUNT=	savoirfairelinux

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-python
USE_LDCONFIG=	yes

USES=		autoreconf compiler:c++11-lib libtool pkgconfig
CFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-I${LOCALBASE}/include

post-stage:
	@${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/opendht.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/pkgconfig
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libopendht.so.0.0.0

.include <bsd.port.mk>
