# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kyototycoon
PORTVERSION=	0.9.56
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://fallabs.com/${PORTNAME}/pkg/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Handy cache/storage server

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libkyotocabinet.so:databases/kyotocabinet

OPTIONS_DEFINE=	DOCS LZO

CONFIGURE_ARGS=	--enable-uyield
CPPFLAGS+=	-fPIC
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_ARGS=	PCDIR=${PREFIX}/libdata/pkgconfig
REINPLACE_ARGS=	-i ''
TEST_TARGET=	check
USE_LDCONFIG=	yes
USES=		gmake pkgconfig

PORTDOCS=	*

LZO_CONFIGURE_OFF=	ac_cv_lib_lzo2_main=no
LZO_CONFIGURE_ON=	ac_cv_lib_lzo2_main=yes
LZO_LIB_DEPENDS=	liblzo2.so:archivers/lzo2

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++ ||g' ${WRKSRC}/configure ${WRKSRC}/doc/spex.html ${WRKSRC}/example/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libkyototycoon.so.2.19.0 ${STAGEDIR}${PREFIX}/libexec/*.so

post-install-DOCS-on:
	${FIND} ${STAGEDIR}${DOCSDIR}/ -type d -exec ${CHMOD} ${BINMODE} {} \;
	${FIND} ${STAGEDIR}${DOCSDIR}/ -type f -exec ${CHMOD} ${DOCMODE} {} \;

.include <bsd.port.mk>
