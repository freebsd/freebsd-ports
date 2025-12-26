PORTNAME=	libcpucycles
DISTVERSION=	20251226
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

pre-configure:
	${ECHO} ${CC} ${CPPFLAGS} ${CFLAGS} ${LDFLAGS} >${WRKSRC}/compilers/default

post-install:
	${MV} ${STAGEDIR}${PREFIX}/man/man1/* ${STAGEDIR}${PREFIX}/share/man/man1/
	${MV} ${STAGEDIR}${PREFIX}/man/man3/* ${STAGEDIR}${PREFIX}/share/man/man3/
	${RMDIR} ${STAGEDIR}${PREFIX}/man/man? ${STAGEDIR}${PREFIX}/man

do-test:
	${SETENVI} LD_LIBRARY_PATH=${STAGEDIR}${PREFIX}/lib ${STAGEDIR}${PREFIX}/bin/cpucycles-info

.include <bsd.port.mk>
