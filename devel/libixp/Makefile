# New ports collection makefile for:	libixp
# Date created:		17 February 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libixp
PORTVERSION=	0.2
CATEGORIES=	devel
MASTER_SITES=	http://www.suckless.org/download/ GENTOO/distfiles

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Standalone client/server 9P library

USE_LDCONFIG=	yes
CFLAGS+=	-I. -fPIC
LDFLAGS+=	-L.
MAKE_ARGS=	PREFIX="${PREFIX}" CC="${CC}" MANPREFIX="${MANPREFIX}/man" \
		CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
MAN1=	ixpc.1
PLIST_FILES=	bin/ixpc include/ixp.h lib/libixp.so lib/libixp.so.0

post-patch:
	@${REINPLACE_CMD} -e 's|\.a|.so|g;/RANLIB/d;s|{AR}|{CC} -shared -fPIC -o|;s|AR|CC|'\
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|"VERSION"|${PORTVERSION}|' ${WRKSRC}/ixpc.c

post-install:
	@${LN} -sf ${PREFIX}/lib/libixp.so ${PREFIX}/lib/libixp.so.0

.include <bsd.port.mk>
