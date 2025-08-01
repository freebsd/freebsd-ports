PORTNAME=	augustus
DISTVERSIONPREFIX=	v
DISTVERSION=	3.5.0
PORTREVISION=	15
CATEGORIES=	biology science
PKGNAMESUFFIX=	-gene-prediction

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Genome annotation tool
WWW=		http://bioinf.uni-greifswald.de/webaugustus/

LICENSE=	GPLv3

LIB_DEPENDS=	libbamtools.so:biology/bamtools \
		libboost_iostreams.so:devel/boost-libs \
		libcolamd.so:math/suitesparse-colamd \
		libgsl.so:math/gsl \
		libhts.so:biology/htslib \
		liblpsolve55.so:math/lp_solve \
		libmysqlpp.so:databases/mysql++
RUN_DEPENDS=	samtools:biology/samtools

USES=		gmake localbase:ldflags mysql perl5 python sqlite shebangfix
USE_CXXSTD=	c++14

USE_GITHUB=	yes
GH_ACCOUNT=	Gaius-Augustus
GH_PROJECT=	Augustus

SHEBANG_GLOB=	*.pl *.py
SHEBANG_FILES=	scripts/checkUTR

CXXFLAGS+=	-I${LOCALBASE}/include/bamtools \
		-I${LOCALBASE}/include/lpsolve \
		-I${LOCALBASE}/include/mysql
LDFLAGS+=	-L${LOCALBASE}/lib/mysql

MAKE_ARGS=	INSTALLDIR=${LOCALBASE}/${PORTNAME} RLN="${RLN}"

BINARY_ALIAS=	make=${GMAKE} python3=${PYTHON_CMD}

TEST_TARGET=	test

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin/*
	@${RM} ${STAGEDIR}${PREFIX}/${PORTNAME}/scripts/pasapolyA2hints.pl.orig

.include <bsd.port.mk>
