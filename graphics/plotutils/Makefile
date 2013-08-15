# Created by: Chuck Robey <chuckr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plotutils
PORTVERSION=	2.6
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	GNU

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Plotting library and toolkit

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png

USES=		gmake motif	# parallel builds are broken with bmake(1)
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--enable-libplotter --enable-libxmi --with-motif
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		ode.1 plot.1 plotfont.1 spline.1 tek2plot.1
INFO=		libxmi plotutils

test: build
	@${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC} ${_MAKE_JOBS} \
		${MAKE_ARGS} check

regression-test: test

.include <bsd.port.mk>
