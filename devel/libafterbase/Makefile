# Created by: ijliao
# $FreeBSD$

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

NO_STAGE=	yes
post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>|g'

.include <bsd.port.mk>
