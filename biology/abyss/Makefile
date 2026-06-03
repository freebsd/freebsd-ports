PORTNAME=	abyss
DISTVERSION=	2.3.10
PORTREVISION=	1
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Assembly By Short Sequences: parallel, paired-end sequence assembler
WWW=		https://www.bcgsc.ca/resources/software/abyss/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	result of comparison of constant 18446744073709551615 with expression of type 'size_t', see https://github.com/bcgsc/abyss/issues/310

BUILD_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:devel/boost-libs \
		ghc:lang/ghc \
		pandoc:textproc/hs-pandoc # pandoc is required just for one man page: abyss-sealer
LIB_DEPENDS=	libbtllib.so:biology/btllib \
		libffi.so:devel/libffi \
		libgmp.so:math/gmp \
		libmpich.so:net/mpich # binaries aren't linked with libmpich.so for some reason
RUN_DEPENDS=	bash:shells/bash \
		gmake:devel/gmake

USES=		autoreconf compiler:c++11-lang gmake iconv:wchar_t localbase:ldflags shebangfix sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	bcgsc

SHEBANG_FILES=	bin/${PORTNAME}-* DataBase/abyss-db-txt
SHEBANG_LANG=	make
make_OLD_CMD=	/usr/bin/make
make_CMD=	${GMAKE}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-sparsehash # configure fails to find std::hash, reported to the ML: https://groups.google.com/forum/#!topic/trans-abyss/SZDBKR5bKxs

TEST_TARGET=	check

PORTSCOUT=	limit:^[0-9\.]*$$ # to ignore alpha-numeric tags

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

TESTING_UNSAFE=	yes # tests fail to compile, see https://github.com/bcgsc/abyss/issues/453

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=unused-but-set-variable
.endif

.include <bsd.port.post.mk>
