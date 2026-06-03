PORTNAME=	lwgrp
DISTVERSION=	1.0.6
CATEGORIES=	devel parallel
MASTER_SITES=	https://github.com/llnl/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	rikka.goering@outlook.de
COMMENT=	Light-weight group library for MPI (LLNL)
WWW=		https://github.com/llnl/lwgrp/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

USES=		libtool localbase mpi:openmpi pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mpi=${MPI_HOME}
CONFIGURE_ENV=	CC=${MPICC}
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

PORTDOCS=	README

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	SHARED
OPTIONS_MULTI=		LIBS
OPTIONS_MULTI_LIBS=	SHARED STATIC
OPTIONS_SUB=		yes

SHARED_DESC=		Build shared libraries
STATIC_DESC=		Build static libraries

SHARED_CONFIGURE_ENABLE=	shared
STATIC_CONFIGURE_ENABLE=	static

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

post-install:
	${RM} -r ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
