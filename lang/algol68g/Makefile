PORTNAME=	algol68g
PORTVERSION=	3.0.6
CATEGORIES=	lang
MASTER_SITES=	http://jmvdveer.home.xs4all.nl/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Algol 68 Genie compiler

LICENSE=	GPLv3+

USES=		readline
GNU_CONFIGURE=	yes
TEST_TARGET=	check

OPTIONS_DEFINE=	GSL PGSQL PLOTUTILS RMATH
OPTIONS_DEFAULT=	GSL PGSQL PLOTUTILS RMATH

GSL_DESC=	Bindings for GNU Scientific Library
GSL_LIB_DEPENDS=	libgsl.so:math/gsl
GSL_CONFIGURE_ENABLE=	gsl

PLOTUTILS_DESC=		Plotting support via plotutils
PLOTUTILS_LIB_DEPENDS=	libplot.so:graphics/plotutils
PLOTUTILS_CONFIGURE_ENABLE=plotutils

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ENABLE=	postgresql

RMATH_DESC=	Bindings for GNU R's statistical routines
RMATH_LIB_DEPENDS=	libRmath.so:math/libRmath
RMATH_CONFIGURE_ENABLE=	mathlib

post-patch:
#	Skip broken check, assume our $CC works
	@${REINPLACE_CMD} -Ee 's/.*(\*-freebsd)/\1/' \
		-e 's|"xgcc"|"x${CC}"|; s/-ldl //' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^install-data-am/s/install-docDATA//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
