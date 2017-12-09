# Created by: ballen
# $FreeBSD$

PORTNAME=	phyml
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.20170530
PORTEPOCH=	1
CATEGORIES=	biology

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple, fast, and accurate algorithm to estimate large phylogenies

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=		fails to compile: c++: the clang compiler does not support '-march=native'
BROKEN_armv6=		fails to compile: c++: the clang compiler does not support '-march=native'
BROKEN_armv7=		fails to compile: c++: the clang compiler does not support '-march=native'

USE_GITHUB=	yes
GH_ACCOUNT=	stephaneguindon

USES=		autoreconf libtool pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-beagle

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/phyml${BIN_SUFFIX}

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_RADIO=		MPI
OPTIONS_RADIO_MPI=	MPICH2 OPENMPI

MPICH2_LIB_DEPENDS=	libmpich.so:net/mpich2
MPICH2_MAKE_ARGS=	CC="${LOCALBASE}/bin/mpicc"
OPENMPI_LIB_DEPENDS=	libmpi.so:net/openmpi
OPENMPI_MAKE_ARGS=	CC="${LOCALBASE}/mpi/openmpi/bin/mpicc"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMPICH2} || ${PORT_OPTIONS:MOPENMPI}
CONFIGURE_ARGS+=	--enable-mpi
BIN_SUFFIX=		-mpi
.else
CONFIGURE_ARGS+=	--disable-mpi
BIN_SUFFIX=		# none
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-O2 .* $${ARCH_flag}|$${CFLAGS}|' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/src/utilities.h

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.pdf \
		${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
