# Created by: G. Adam Stanislav <adam@whizkidtech.net>
# $FreeBSD$

PORTNAME=	fastcrc
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.whizkidtech.redprince.net/fports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast CRC routines

BUILD_DEPENDS=	nasm:devel/nasm

ONLY_FOR_ARCHS=	i386

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|gcc|$${CC}| ; \
		 /strip/d' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/fastcrc.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libfcrc.so.1 ${STAGEDIR}${PREFIX}/lib
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfcrc.so.1
	${LN} -fs libfcrc.so.1 ${STAGEDIR}${PREFIX}/lib/libfcrc.so

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
