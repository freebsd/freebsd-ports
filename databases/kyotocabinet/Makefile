PORTNAME=	kyotocabinet
PORTVERSION=	1.2.80
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	https://dbmx.net/kyotocabinet/pkg/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Straightforward implementation of DBM
WWW=		https://dbmx.net/kyotocabinet/

LICENSE=	GPLv3

BROKEN_mips=		fails to link: hidden symbol '__sync_lock_test_and_set_8' in /usr/lib/libgcc.a(stdatomic.o) is referenced by DSO
BROKEN_mips64=		fails to link: hidden symbol '__sync_lock_test_and_set_8' in /usr/lib/libgcc.a(stdatomic.o) is referenced by DSO

USES=		compiler:c++11-lang gmake

CPPFLAGS+=	-fPIC
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_ARGS=	PCDIR=${PREFIX}/libdata/pkgconfig
REINPLACE_ARGS=	-i ''
TEST_TARGET=	check
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++ ||g' ${WRKSRC}/configure ${WRKSRC}/doc/spex.html ${WRKSRC}/example/Makefile ${WRKSRC}/lab/kcdict/Makefile
	@${REINPLACE_CMD} -e 's|-g0 -O2||g' \
	    ${PATCH_WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-march=native||g' \
	    ${PATCH_WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-m64 ||g' \
	    ${PATCH_WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libkyotocabinet.so

post-install-DOCS-on:
	${FIND} ${STAGEDIR}${DOCSDIR}/ -type d -exec ${CHMOD} ${BINMODE} {} +
	${FIND} ${STAGEDIR}${DOCSDIR}/ -type f -exec ${CHMOD} ${DOCMODE} {} +

.include <bsd.port.mk>
