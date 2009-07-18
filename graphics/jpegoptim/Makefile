# New ports collection makefile for:	DirectFB
# Date created:				24 January 2003
# Whom:					Devaux Fabien <fab@gcu.info>
#
# $FreeBSD$
#

PORTNAME=	jpegoptim
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.kokkonen.net/tjko/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to optimize jpeg files

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-libjpeg=${LOCALBASE}
MAKE_ARGS=	mandir=${MANPREFIX}/man

MAN1=		jpegoptim.1
PLIST_FILES=	bin/jpegoptim

.include <bsd.port.mk>
