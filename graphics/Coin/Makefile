# New ports collection makefile for:	Coin
# Date created:				10 May 2002
# Whom:					roland.jesse@gmx.net
#
# $FreeBSD$
#

PORTNAME=	Coin
PORTVERSION=	1.0.3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.coin3d.org/pub/coin/src/

MAINTAINER=	roland.jesse@gmx.net

LIB_DEPENDS=	simage.22:${PORTSDIR}/graphics/simage

USE_REINPLACE=	yes
USE_MESA=	yes
USE_XLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--program-transform-name="s/x/x/"
INSTALLS_SHLIB=	yes

MAN1=		coin-config.1

post-patch:
	@${REINPLACE_CMD} -e 's|DATA install-data-local|DATA|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
