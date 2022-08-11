PORTNAME=	libixp
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://dl.suckless.org/libs/

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Standalone client/server 9P library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/libixp/LICENSE

USE_LDCONFIG=	yes
MAKE_ARGS=	PREFIX="${PREFIX}" CC="${CC} -c" LD="${CC}" \
		CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
CFLAGS+=	-I. -I${WRKSRC}/include -fPIC
LDFLAGS+=	-L. -L${WRKSRC}/lib

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
	cd ${WRKSRC}; ${MAKE_ENV} ${MAKE};

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/ixp.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/ixp_srvutil.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libixp.so ${STAGEDIR}${PREFIX}/lib/libixp.so.1
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libixp_pthread.so \
		${STAGEDIR}${PREFIX}/lib/libixp_pthread.so.1
	${LN} -sf libixp.so.1 ${STAGEDIR}${PREFIX}/lib/libixp.so
	${LN} -sf libixp_pthread.so.1 ${STAGEDIR}${PREFIX}/lib/libixp_pthread.so
	${INSTALL_PROGRAM} ${WRKSRC}/cmd/ixpc.O ${STAGEDIR}${PREFIX}/bin/ixpc
	${INSTALL_MAN} ${WRKSRC}/man/ixpc.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
