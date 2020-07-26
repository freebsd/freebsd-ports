# $FreeBSD$

PORTNAME=	rinutils
DISTVERSION=	0.4.1
CATEGORIES=	devel
MASTER_SITES=	https://raw.githubusercontent.com/${GH_ACCOUNT}/shlomif-cmake-modules/master/shlomif-cmake-modules/:cmakemodule
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${_CMAKE_MODULE}:cmakemodule
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	C11 / gnu11 utilities C library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake perl5 pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	shlomif
USE_PERL5=	build
CMAKE_OFF=	WITH_TEST_SUITE

_CMAKE_MODULE=	Shlomif_Common.cmake

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${_CMAKE_MODULE} ${WRKSRC}/cmake/

.include <bsd.port.mk>
