PORTNAME=	libcircle
DISTVERSION=	0.3.0
CATEGORIES=	devel parallel
MASTER_SITES=	https://github.com/hpc/${PORTNAME}/releases/download/v${DISTVERSION:R}/

MAINTAINER=	rikka.goering@outlook.de
COMMENT=	Efficient distributed work queue library for MPI clusters
WWW=		https://hpc.github.io/libcircle/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool localbase mpi:openmpi pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CC=${MPICC} \
		MPICC=${MPICC}
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS DOXYGEN
OPTIONS_DEFAULT=	SHARED
OPTIONS_MULTI=		LIBS
OPTIONS_MULTI_LIBS=	SHARED STATIC
OPTIONS_SUB=		yes

SHARED_DESC=		Build shared libraries
STATIC_DESC=		Build static libraries

DOXYGEN_IMPLIES=		DOCS
DOXYGEN_BUILD_DEPENDS=		doxygen:devel/doxygen
DOXYGEN_CONFIGURE_ENABLE=	doxygen

SHARED_CONFIGURE_ENABLE=	shared
STATIC_CONFIGURE_ENABLE=	static

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${STAGEDIR}${DOCSDIR}

do-install-DOXYGEN-on:
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "html latex" ${STAGEDIR}${DOCSDIR})
	${INSTALL_MAN} ${WRKSRC}/doc/man/man3/*.3 ${STAGEDIR}${PREFIX}/share/man/man3

.include <bsd.port.mk>
