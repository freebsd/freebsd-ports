# New ports collection makefile for:	Coin
# Date created:				10 May 2002
# Whom:					roland.jesse@gmx.net
#
# $FreeBSD$
#

PORTNAME=	Coin
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.coin3d.org/pub/coin/src/

MAINTAINER=	roland.jesse@gmx.net
COMMENT=	C++ 3D graphics library based on the Open Inventor 2.1 API

BUILD_DEPENDS=	doxygen:${PORTSDIR}/devel/doxygen
LIB_DEPENDS=	simage.22:${PORTSDIR}/graphics/simage \
		openal.0:${PORTSDIR}/audio/openal

USE_REINPLACE=	yes
USE_GL=		yes
USE_XLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--program-transform-name="s/x/x/" --with-pthread=yes --enable-threadsafe \
		--enable-3ds-import --enable-sound --enable-html
INSTALLS_SHLIB=	yes

MAN1=		coin-config.1

post-patch:
	@${REINPLACE_CMD} -e 's|DATA install-data-local|DATA|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
