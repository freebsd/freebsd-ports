# $FreeBSD$

PORTNAME=	abyss
DISTVERSION=	2.2.4
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Assembly By Short Sequences: parallel, paired-end sequence assembler

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	result of comparison of constant 18446744073709551615 with expression of type 'size_t', see https://github.com/bcgsc/abyss/issues/310

BUILD_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:devel/boost-libs \
		ghc:lang/ghc \
		pandoc:textproc/hs-pandoc # pandoc is required just for one man page: abyss-sealer
LIB_DEPENDS=	libffi.so:devel/libffi \
		libgmp.so:math/gmp
RUN_DEPENDS=	bash:shells/bash \
		gmake:devel/gmake

USES=		autoreconf compiler:c++11-lang gmake iconv:wchar_t localbase:ldflags shebangfix sqlite
SHEBANG_FILES=	bin/${PORTNAME}-* DataBase/abyss-db-txt
SHEBANG_LANG=	make
make_OLD_CMD=	/usr/bin/make
make_CMD=	${PREFIX}/bin/gmake
USE_GITHUB=	yes
GH_ACCOUNT=	bcgsc
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-sparsehash # configure fails to find std::hash, reported to the ML: https://groups.google.com/forum/#!topic/trans-abyss/SZDBKR5bKxs

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
