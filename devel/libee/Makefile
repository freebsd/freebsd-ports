# Created by: Jim Riggs <ports@christianserving.org>
# $FreeBSD$

PORTNAME=	libee
PORTVERSION=	0.4.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://download.rsyslog.com/

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Event expression library inspired by CEE

DEPRECATED=	No longer required by rsyslog, which was its only consumer.  No longer maintained upstream
EXPIRATION_DATE=	2019-09-23

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libestr.so:devel/libestr

USES=		libtool pathfix
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBESTR_CFLAGS="-I${LOCALBASE}/include" LIBESTR_LIBS="-L${LOCALBASE}/lib -lestr"
CONFIGURE_ARGS+=	--disable-testbench

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
