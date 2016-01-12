# Created by: ijliao
# $FreeBSD$

PORTNAME=	libafterbase
PORTVERSION=	0.92
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/afterstep/libAfterBase/${PORTVERSION}
DISTNAME=	libAfterBase-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AfterStep basic functionality library

LICENSE=	LGPL21+

USES=		desthack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-staticlibs --enable-sharedlibs --with-x
USE_LDCONFIG=	yes
PLIST_SUB=	STATIC="@comment "

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>|g'

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libAfterBase.so

.include <bsd.port.mk>
