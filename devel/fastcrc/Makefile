# Created by: G. Adam Stanislav <adam@whizkidtech.net>
# $FreeBSD$

PORTNAME=	fastcrc
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	http://www.whizkidtech.redprince.net/fports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast CRC routines

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

ONLY_FOR_ARCHS=	i386

USE_LDCONFIG=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e \
		's|gcc|$${CC}| ; \
		 /strip/d' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fc ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/fastcrc.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libfcrc.so.1 ${PREFIX}/lib
	${LN} -fs ${PREFIX}/lib/libfcrc.so.1 ${PREFIX}/lib/libfcrc.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
