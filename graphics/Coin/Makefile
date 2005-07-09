# New ports collection makefile for:	Coin
# Date created:				10 May 2002
# Whom:					roland.jesse@gmx.net
#
# $FreeBSD$
#

PORTNAME=	Coin
PORTVERSION=	2.3.0
CATEGORIES=	graphics
MASTER_SITES=	http://ftp.coin3d.org/coin/src/all/ \
		ftp://ftp.coin3d.org/pub/coin/src/all/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ 3D graphics library based on the Open Inventor 2.1 API

LIB_DEPENDS=	openal.0:${PORTSDIR}/audio/openal \
		simage.26:${PORTSDIR}/graphics/simage

USE_GL=		yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-pthread=yes --enable-threadsafe \
		--enable-3ds-import --enable-sound
INSTALLS_SHLIB=	yes

MAN1=		coin-config.1

post-patch:
	@${REINPLACE_CMD} -e 's|DATA install-data-local|DATA|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
