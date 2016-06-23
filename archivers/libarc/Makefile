# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libarc
PORTVERSION=	2.0.2
PORTREVISION=	2
CATEGORIES=	archivers devel
MASTER_SITES=	http://www.onicos.com/staff/iz/release/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tiny C decompression library for several popular compression formats

SOLIB=		libarc.so
SOVERSION=	1

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I." LN="${LN} -sf" \
		SOLIB="${SOLIB}" SOVERSION="${SOVERSION}"
USE_LDCONFIG=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arccat ${STAGEDIR}/${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${SOLIB}.${SOVERSION} ${STAGEDIR}/${PREFIX}/lib
	${LN} -sf ${SOLIB}.${SOVERSION} ${STAGEDIR}/${PREFIX}/lib/${SOLIB}
	@${MKDIR} ${STAGEDIR}/${PREFIX}/include/libarc
	${INSTALL_DATA} ${WRKSRC}/libarc/* ${STAGEDIR}/${PREFIX}/include/libarc
	(cd ${WRKSRC} && ${INSTALL_DATA} unlzh.h zip.h ${STAGEDIR}/${PREFIX}/include/libarc)

.include <bsd.port.mk>
