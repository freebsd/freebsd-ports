# New ports collection makefile for:	DirectFB
# Date created:				24 January 2003
# Whom:					Devaux Fabien <fab@gcu.info>
#
# $FreeBSD$
#

PORTNAME=	jpegoptim
PORTVERSION=	1.2.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.cc.jyu.fi/~tjko/src/

MAINTAINER=	fab@gcu.info
COMMENT=	An utility to optimize jpeg files

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-libjpeg=${LOCALBASE}

MAN1=		jpegoptim.1
PLIST_FILES=	bin/jpegoptim

.include <bsd.port.mk>
