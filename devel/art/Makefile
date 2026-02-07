PORTNAME=	art
PORTVERSION=	0.9.02
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/art-project/src/

MAINTAINER=	virtual.lark@gmail.com
COMMENT=	Resource tracing, debugging, and profiling tool
WWW=		https://github.com/larkvirtual/restracer/

LICENSE=	GPLv3

LIB_DEPENDS=	libxml++-2.6.so:textproc/libxml++26

USES=		compiler:c++11-lang gmake pkgconfig
USE_CXXSTD=	c++11
TEST_TARGET=	test

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC} -type f -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e '/$$(CXX)/s,CFLAGS,CXXFLAGS,' \
		-e 's,^CFLAGS+=,CXXFLAGS+=,'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/artlibgen/src/artlibgen \
		${WRKSRC}/artrepgen/artrepgen ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in posix-gcc-mt-file-lint.xml posix-gcc-mt-netw-lint.xml \
 posix-gcc-mt-file-special.xml
	${INSTALL_DATA} ${WRKSRC}/artlibgen/templates/${docs} \
		${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
