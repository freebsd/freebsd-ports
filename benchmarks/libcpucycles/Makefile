PORTNAME=	libcpucycles
DISTVERSION=	20250925
CATEGORIES=	benchmarks devel
MASTER_SITES=	https://cpucycles.cr.yp.to/

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Microlibrary for counting CPU cycles
WWW=		https://cpucycles.cr.yp.to/

LICENSE=	PD

USES=		python:build shebangfix
USE_LDCONFIG=	yes
SHEBANG_FILES=	configure scripts-build/*
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--host=${ARCH}
ALL_TARGET=	default
CFLAGS+=	-fPIC -fwrapv -fvisibility=hidden

_STAGE=	${WRKSRC}/build/0/package

pre-configure:
	${ECHO} ${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} >${WRKSRC}/compilers/default

# no staging support for some reason
do-install:
	${INSTALL_MAN} ${_STAGE}/man/man1/cpucycles-info.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${_STAGE}/man/man3/cpucycles.3 ${STAGEDIR}${PREFIX}/share/man/man3/
	${INSTALL_DATA} ${_STAGE}/include/cpucycles.h ${STAGEDIR}${PREFIX}/include/
	for lib in ${_STAGE}/lib/libcpucycles* ; \
	do \
		${INSTALL_LIB} $$lib ${STAGEDIR}${PREFIX}/lib/ ; \
	done
	${INSTALL_PROGRAM} ${_STAGE}/bin/cpucycles-info ${STAGEDIR}${PREFIX}/bin/

do-test:
	${SETENVI} LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib ${STAGEDIR}${PREFIX}/bin/cpucycles-info

.include <bsd.port.mk>
