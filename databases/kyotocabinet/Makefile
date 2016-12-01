# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	kyotocabinet
PORTVERSION=	1.2.76
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://fallabs.com/${PORTNAME}/pkg/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Straightforward implementation of DBM

LICENSE=	GPLv3

OPTIONS_DEFINE=	DOCS

CPPFLAGS+=	-fPIC
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_ARGS=	PCDIR=${PREFIX}/libdata/pkgconfig
REINPLACE_ARGS=	-i ''
TEST_TARGET=	check
USE_LDCONFIG=	yes
USES=		gmake

NOT_FOR_ARCHS=	powerpc
NOT_FOR_ARCHS_REASON=	does not link

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++ ||g' ${WRKSRC}/configure ${WRKSRC}/doc/spex.html ${WRKSRC}/example/Makefile ${WRKSRC}/lab/kcdict/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libkyotocabinet.so.16.13.0
	${FIND} ${STAGEDIR}${DOCSDIR}/ -type d -exec ${CHMOD} ${BINMODE} {} \;
	${FIND} ${STAGEDIR}${DOCSDIR}/ -type f -exec ${CHMOD} ${DOCMODE} {} \;

.include <bsd.port.mk>
