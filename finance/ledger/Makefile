# Created by: wcarey
# $FreeBSD$

PORTNAME=	ledger
PORTVERSION=	2.6.3
PORTREVISION=	3
CATEGORIES=	finance
MASTER_SITES=	http://cloud.github.com/downloads/jwiegley/${PORTNAME}/

MAINTAINER=	woodycarey@hotmail.com
COMMENT=	John Wiegley's command line accounting program

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libxmltok.so:${PORTSDIR}/www/libwww \
		libxmlparse.so:${PORTSDIR}/www/libwww

USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/w3c-libwww
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

INSTALL_TARGET=	install-strip

INFO=	ledger

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/scripts
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${STAGEDIR}${EXAMPLESDIR}/scripts/
	${INSTALL_DATA} ${WRKSRC}/sample.dat ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/setup.py ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ledger.vim ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
