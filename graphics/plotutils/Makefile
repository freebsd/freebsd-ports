# Created by: Chuck Robey <chuckr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plotutils
PORTVERSION=	2.6
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	GNU

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Plotting library and toolkit

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

USES=		gmake motif libtool	# parallel builds are broken with bmake(1)
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-libplotter --enable-libxmi --with-motif
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		libxmi plotutils

test: build
	@${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} ${_MAKE_JOBS} \
		${MAKE_ARGS} check

regression-test: test

.include <bsd.port.mk>
