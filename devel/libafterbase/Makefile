# ex:ts=8
# New ports collection makefile for:	libAfterBase
# Date created:			Oct 7, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libafterbase
PORTVERSION=	0.92
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/afterstep/libAfterBase/${PORTVERSION}
DISTNAME=	libAfterBase-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AfterStep basic functionality library

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-staticlibs --enable-sharedlibs --with-x
USE_LDCONFIG=	yes
PLIST_SUB=	STATIC="@comment "

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>|g'

.include <bsd.port.mk>
