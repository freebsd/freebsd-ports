# $FreeBSD$

PORTNAME=	abyss
DISTVERSION=	2.1.5
CATEGORIES=	biology
MASTER_SITES=	http://www.bcgsc.ca/platform/bioinfo/software/${PORTNAME}/releases/${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Assembly By Short Sequences: parallel, paired-end sequence assembler

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/boost/version.hpp:devel/boost-libs \
		ghc:lang/ghc \
		pandoc:textproc/hs-pandoc # pandoc is required just for one man page: abyss-sealer
LIB_DEPENDS=	libffi.so:devel/libffi \
		libgmp.so:math/gmp \
		libomp.so:devel/openmp
RUN_DEPENDS=	bash:shells/bash \
		gmake:devel/gmake

USES=		gmake iconv:wchar_t localbase:ldflags shebangfix sqlite
SHEBANG_FILES=	bin/${PORTNAME}-*
SHEBANG_LANG=	make
make_OLD_CMD=	/usr/bin/make
make_CMD=	${PREFIX}/bin/gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-sparsehash # configure fails to find std::hash, reported to the ML: https://groups.google.com/forum/#!topic/trans-abyss/SZDBKR5bKxs

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
