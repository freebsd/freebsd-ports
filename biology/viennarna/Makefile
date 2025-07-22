PORTNAME=	viennarna
DISTVERSION=	2.7.0
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	https://www.tbi.univie.ac.at/RNA/download/sourcecode/2_7_x/
DISTNAME=	ViennaRNA-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Alignment tools for the structural analysis of RNA
WWW=		https://www.tbi.univie.ac.at/RNA/ \
		https://github.com/ViennaRNA/ViennaRNA

LICENSE=	ViennaRNALicense
LICENSE_NAME=	Vienna RNA License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror

BROKEN_FreeBSD_13=	compilation fails with clang-19: see https://github.com/ViennaRNA/ViennaRNA/issues/253
BROKEN_FreeBSD_15=	compilation fails with clang-19: see https://github.com/ViennaRNA/ViennaRNA/issues/253

BUILD_DEPENDS=	bash:shells/bash \
		lapacke>0:math/lapacke \
		libgd>0:graphics/gd # for the static lib
BUILD_DEPENDS+=	swig:devel/swig \
		xxd:sysutils/xxd
LIB_DEPENDS=	libgmp.so:math/gmp \
		libgsl.so:math/gsl \
		liblapack.so:math/lapack \
		libmpfr.so:math/mpfr

USES=		autoreconf bison compiler:c++17-lang fortran gmake \
		libtool localbase perl5 pkgconfig xorg # w/out autoreconf -lstdc++ is present in configure and Makefiles and this causes link failure
USE_XORG=	ice x11 xext # only for build

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_SHELL=	${PREFIX}/bin/bash
CONFIGURE_ARGS=	--enable-shared --disable-static --with-gsl --with-cluster --with-kinwalker --enable-mpfr --without-python --without-python3 --without-perl

CXXFLAGS+=	-Dregister= # workaround for https://github.com/ViennaRNA/ViennaRNA/issues/214

TEST_TARGET=	check

CONFLICTS_INSTALL=	g2 # include/g2.h

INFO=		RNAlib

DATASDIR=	${PREFIX}/share/ViennaRNA
DOCSDIR=	${PREFIX}/share/doc/ViennaRNA
EXAMPLESDIR=	${PREFIX}/share/examples/ViennaRNA

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

post-configure: # remove -lstdc++ from .pc file
	@${REINPLACE_CMD} -e 's| -lstdc++||' ${WRKSRC}/RNAlib2.pc

post-install:
	# remove stray files
	@${RM} ${STAGEDIR}/RNA/RNAconsensus.py
	@${RMDIR} ${STAGEDIR}/RNA

.include <bsd.port.mk>
