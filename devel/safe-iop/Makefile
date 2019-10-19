# Created by: stas
# $FreeBSD$

PORTNAME=	safe-iop
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://BSDforge.com/projects/source/devel/safe-iop/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Safe integer operation library for C

USES=		tar:tgz
USE_LDCONFIG=	yes
ALL_TARGET=	so
CFLAGS+=	-fPIC
PLIST_FILES=	include/safe_iop.h \
		lib/libsafe_iop.so.0

post-patch:
	@${REINPLACE_CMD} -E -e 's,(^CC[[:space:]]*=.*),#\1,' \
	    -e 's,(^CFLAGS[[:space:]]*)=.*,\1+= -Iinclude,' \
	    -e 's,(^VERSION[[:space:]]*=[[:space:]]*[[:digit:]]+).*,\1,' \
	    ${WRKSRC}/Makefile

do-install:
	${INSTALL_LIB} ${WRKSRC}/libsafe_iop.so.0 ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/safe_iop.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
