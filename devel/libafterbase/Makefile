PORTNAME=	libafterbase
PORTVERSION=	0.92
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/afterstep/libAfterBase/${PORTVERSION}
DISTNAME=	libAfterBase-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	AfterStep basic functionality library

LICENSE=	LGPL21+

USES=		desthack
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-staticlibs --enable-sharedlibs --with-x

PLIST_SUB=	STATIC="@comment "

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

post-patch:
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>|g'

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libAfterBase.so

.include <bsd.port.post.mk>
