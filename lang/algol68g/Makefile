PORTNAME=	algol68g
PORTVERSION=	3.5.12
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	https://jmvdveer.home.xs4all.nl/ LOCAL/danfe

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Algol 68 Genie hybrid compiler-interpreter
WWW=		https://www.xs4all.nl/~jmvdveer/algol.html

LICENSE=	GPLv3+

USES=		readline
GNU_CONFIGURE=	yes
TEST_TARGET=	check

PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	CURL DOCS GSL PGSQL PLOTUTILS RMATH
OPTIONS_DEFAULT=	CURL GSL PGSQL PLOTUTILS RMATH

CURL_LIB_DEPENDS=	libcurl.so:ftp/curl
CURL_CONFIGURE_ENABLE=	curl

GSL_DESC=		Bindings for GNU Scientific Library
GSL_LIB_DEPENDS=	libgsl.so:math/gsl
GSL_CONFIGURE_ENABLE=	gsl

PLOTUTILS_DESC=		Plotting support via plotutils
PLOTUTILS_LIB_DEPENDS=	libplot.so:graphics/plotutils
PLOTUTILS_CONFIGURE_ENABLE=plotutils

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ENABLE=	postgresql

RMATH_DESC=		Bindings for GNU R's statistical routines
RMATH_LIB_DEPENDS=	libRmath.so:math/libRmath
RMATH_CONFIGURE_ENABLE=	mathlib

post-patch:
# Trim architecture constraints from the target triple to build properly
# on every platform FreeBSD supports (now or in the future)
	@${REINPLACE_CMD} -e 's/.*\(\*-freebsd\)/\1/' ${WRKSRC}/configure
# Do not install GPLv3 boilerplate and ChangeLog which redirects to NEWS
	@${REINPLACE_CMD} -e '/^doc_DATA/s/ COPYING ChangeLog//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
