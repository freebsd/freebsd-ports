# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kyototycoon
PORTVERSION=	0.9.56
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://fallabs.com/${PORTNAME}/pkg/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Handy cache/storage server

LICENSE=	GPLv3

LIB_DEPENDS=	libkyotocabinet.so:databases/kyotocabinet

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--enable-uyield
CPPFLAGS+=	-fPIC
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_ARGS=	PCDIR=${PREFIX}/libdata/pkgconfig
REINPLACE_ARGS=	-i ''
TEST_TARGET=	check
USE_LDCONFIG=	yes
USES=		gmake pkgconfig

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++ ||g' ${WRKSRC}/configure ${WRKSRC}/doc/spex.html ${WRKSRC}/example/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libkyototycoon.so.2.19.0 ${STAGEDIR}${PREFIX}/libexec/*.so
	${FIND} ${STAGEDIR}${DOCSDIR}/ -type d -exec ${CHMOD} ${BINMODE} {} \;
	${FIND} ${STAGEDIR}${DOCSDIR}/ -type f -exec ${CHMOD} ${DOCMODE} {} \;

.include <bsd.port.mk>
