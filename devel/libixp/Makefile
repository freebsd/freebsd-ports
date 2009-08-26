# New ports collection makefile for:	libixp
# Date created:		17 February 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libixp
PORTVERSION=	0.5
CATEGORIES=	devel
MASTER_SITES=	http://dl.suckless.org/libs/

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Standalone client/server 9P library

USE_LDCONFIG=	yes
CFLAGS+=	-I. -I${WRKSRC}/include -fPIC
LDFLAGS+=	-L. -L${WRKSRC}/lib
MAKE_ARGS=	PREFIX="${PREFIX}" CC="${CC} -c" LD="${CC}" \
		CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		ixpc.1

post-patch:
	@${REINPLACE_CMD} -e 's|\.a|.so|g; s|(AR)|(LD) -shared -fPIC -o|' \
		${WRKSRC}/mk/lib.mk ${WRKSRC}/mk/hdr.mk
	@${REINPLACE_CMD} -e 's|\.sowk|.awk|' ${WRKSRC}/mk/hdr.mk
	@${REINPLACE_CMD} -e 's|\(echo.*\)AR\(.*\)|\1LD\2|' ${WRKSRC}/mk/lib.mk
	@${REINPLACE_CMD} -e 's|CFLAGS += $$(DEBUGCFLAGS) -O0 $$(INCS)|& -fPIC|' \
		${WRKSRC}/config.mk
	@${REINPLACE_CMD} -e 's|VERSION|"${PORTVERSION}.${PORTREVISION}"|' \
		${WRKSRC}/cmd/ixpc.c

do-build:
	cd ${WRKSRC}; ${MAKE};

do-install:
	@${INSTALL_DATA} ${WRKSRC}/include/ixp.h ${PREFIX}/include
	@${INSTALL_DATA} ${WRKSRC}/include/ixp_srvutil.h ${PREFIX}/include
	@${INSTALL_PROGRAM} ${WRKSRC}/lib/libixp.so ${PREFIX}/lib/libixp.so.1
	@${INSTALL_PROGRAM} ${WRKSRC}/lib/libixp_pthread.so \
		${PREFIX}/lib/libixp_pthread.so.1
	@${LN} -sf libixp.so.1 ${PREFIX}/lib/libixp.so
	@${LN} -sf libixp_pthread.so.1 ${PREFIX}/lib/libixp_pthread.so
	@${INSTALL_PROGRAM} ${WRKSRC}/cmd/ixpc.O ${PREFIX}/bin/ixpc
	@${INSTALL_MAN} ${WRKSRC}/man/ixpc.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
