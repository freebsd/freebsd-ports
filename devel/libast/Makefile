# Created by: Jeremy Norris <ishmael27@home.com>
# $FreeBSD$

PORTNAME=	libast
PORTVERSION=	0.7
PORTREVISION=	13
CATEGORIES=	devel
MASTER_SITES=	http://www.eterm.org/download/ \
		LOCAL/ehaupt

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Library of assorted spiffy things

LICENSE=	MIT

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libImlib2.so:graphics/imlib2

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USES=		libtool pathfix

.if defined(MACHINE_CPU) && ${MACHINE_CPU:Mmmx}
CONFIGURE_ARGS+=--enable-mmx
.endif

.include <bsd.port.mk>
