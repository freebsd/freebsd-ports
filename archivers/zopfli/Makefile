# Created by: Alexander Kuehn <freebsd@nagilum.org>
# $FreeBSD$

PORTNAME=	zopfli
DISTVERSION=	1.0.0-31
DISTVERSIONSUFFIX=	-g6ff3ba2
CATEGORIES=	archivers

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Zopfli Compression Algorithm

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	google

USES=		gmake

ALL_TARGET=	${PORTNAME} ${PORTNAME}png \
		lib${PORTNAME} lib${PORTNAME}png
MAKE_ARGS=	CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS} ${LDFLAGS}" \
		CXXFLAGS="${CXXFLAGS}"
CFLAGS+=	-fPIC # XXX Convert into an implicit rule
LDFLAGS+=	-lm
USE_LDCONFIG=	yes

MAKE_JOBS_UNSAFE=	yes

do-install:
.for f in ${PORTNAME} ${PORTNAME}png
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
.for f in lib${PORTNAME}.so.1.0.1 lib${PORTNAME}png.so.1.0.0
	${INSTALL_LIB} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/lib
	${LN} -fs ${f} ${STAGEDIR}${PREFIX}/lib/${f:R:R}
	${LN} -fs ${f:R:R} ${STAGEDIR}${PREFIX}/lib/${f:R:R:R}
.endfor
	(cd ${WRKSRC}/src && ${COPYTREE_SHARE} \
		"zopfli zopflipng" ${STAGEDIR}${PREFIX}/include \
		"-name *.h")

.include <bsd.port.mk>
