PORTNAME=	fastcrc
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.whizkidtech.redprince.net/fports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast CRC routines
WWW=		http://www.whizkidtech.redprince.net/fports/

LICENSE=	BSD2CLAUSE

DEPRECATED=	dead upstream
EXPIRATION_DATE=	2025-12-31

ONLY_FOR_ARCHS=	i386

BUILD_DEPENDS=	nasm:devel/nasm

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|gcc|$${CC}| ; \
		 s@^LDOPT=.*@& -z notext@ ; \
		 /strip/d' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/fastcrc.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_LIB} ${WRKSRC}/libfcrc.so.1 ${STAGEDIR}${PREFIX}/lib
	${LN} -fs libfcrc.so.1 ${STAGEDIR}${PREFIX}/lib/libfcrc.so

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
