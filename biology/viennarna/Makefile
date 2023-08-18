PORTNAME=	viennarna
DISTVERSION=	2.6.3
CATEGORIES=	biology
MASTER_SITES=	https://www.tbi.univie.ac.at/RNA/download/sourcecode/2_6_x/
DISTNAME=	ViennaRNA-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Alignment tools for the structural analysis of RNA
WWW=		https://www.tbi.univie.ac.at/RNA/

LICENSE=	ViennaRNALicense
LICENSE_NAME=	Vienna RNA License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror

BROKEN_FreeBSD_14=	fails to compile: no member named 'bind2nd' in namespace 'std'

BUILD_DEPENDS=	bash:shells/bash \
		libgd>0:graphics/gd # for the static lib
LIB_DEPENDS=	libgmp.so:math/gmp \
		libgsl.so:math/gsl \
		liblapack.so:math/lapack \
		libmpfr.so:math/mpfr \
		libopenblas.so:math/openblas

USES=		autoreconf compiler:c++11-lang fortran gmake libtool localbase perl5 pkgconfig xorg # w/out autoreconf -lstdc++ is present in configure and Makefiles and this causes link failure
USE_XORG=	x11 xext # only for build

GNU_CONFIGURE=	yes
CONFIGURE_SHELL=	${PREFIX}/bin/bash
CONFIGURE_ARGS=	--enable-shared --disable-static --with-gsl --with-cluster --with-kinwalker --enable-mpfr --without-python --without-python3 --without-perl

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

.include <bsd.port.mk>
