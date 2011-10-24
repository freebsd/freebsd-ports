# ports collection makefile for:	safe-iop
# Date created:				09/26/2010
# Whom:					stas
#
# $FreeBSD$
#

PORTNAME=	safe-iop
PORTVERSION=	0.3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A safe integer operation library for C

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
	${INSTALL_PROGRAM} ${WRKSRC}/libsafe_iop.so.0 ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/include/safe_iop.h ${PREFIX}/include/

.include <bsd.port.mk>
