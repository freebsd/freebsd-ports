PORTNAME=	phyml
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.20220408
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	biology

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple, fast, and accurate algorithm to estimate large phylogenies
WWW=		https://github.com/stephaneguindon/phyml

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	stephaneguindon

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-beagle --disable-native

PLIST_FILES=	bin/phyml${BIN_SUFFIX}
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_RADIO=		MPI
OPTIONS_RADIO_MPI=	MPICH OPENMPI

MPICH_LIB_DEPENDS=	libmpich.so:net/mpich
MPICH_MAKE_ARGS=	CC="${LOCALBASE}/bin/mpicc"
OPENMPI_LIB_DEPENDS=	libmpi.so:net/openmpi
OPENMPI_MAKE_ARGS=	CC="${LOCALBASE}/mpi/openmpi/bin/mpicc"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMPICH} || ${PORT_OPTIONS:MOPENMPI}
CONFIGURE_ARGS+=	--enable-mpi
BIN_SUFFIX=		-mpi
.else
CONFIGURE_ARGS+=	--disable-mpi
BIN_SUFFIX=		# none
.endif

.if ${ARCH} != amd64 && ${ARCH} != i386
post-patch:
	@${REINPLACE_CMD} -e 's|VECTOR_FLAG=-march=native|dnl &|' -e 's|-msse3 ||' ${WRKSRC}/configure.ac
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.pdf \
		${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
