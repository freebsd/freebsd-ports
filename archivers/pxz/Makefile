PORTNAME=	pxz
PORTVERSION=	0.20220509
CATEGORIES=	archivers

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parallel LZMA compressor using liblzma

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe tar:xz
PLIST_FILES=	bin/pxz share/man/man1/pxz.1.gz

USE_GITHUB=	yes
GH_ACCOUNT=	jnovy
GH_PROJECT=	pxz
GH_TAGNAME=	136e5c2

CPE_VENDOR=	pxz_project

MAKE_ENV+=	BINDIR=${PREFIX}/bin \
		MANDIR=${PREFIX}/share/man

MAKE_ARGS+=	CC="${CC}"

.if !exists(/usr/include/omp.h)
USES+=		compiler:gcc-c++11-lib
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pxz

.include <bsd.port.mk>
