# $FreeBSD$

PORTNAME=	algol68g
PORTVERSION=	2.8
CATEGORIES=	lang
MASTER_SITES=	http://jmvdveer.home.xs4all.nl/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Algol 68 Genie compiler

LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl

OPTIONS_DEFINE=	GNUPLOT PGSQL
OPTIONS_DEFAULT=GNUPLOT PGSQL

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-compiler

PLIST_DIRS=	include/algol68g
PLIST_FILES=	bin/a68g man/man1/a68g.1.gz \
		include/algol68g/a68g.h include/algol68g/a68g-config.h

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUPLOT}
LIB_DEPENDS+=	libplot.so:${PORTSDIR}/graphics/plotutils
.else
CONFIGURE_ARGS+=--disable-plotutils
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
.else
CONFIGURE_ARGS+=--disable-postgresql
.endif

post-patch:
#	Skip broken check, assume our $CC works
	@${REINPLACE_CMD} -Ee 's/.*(\*-freebsd)/\1/' \
		-e 's/"xgcc"/"x${CC}"/; s/-ldl //' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^install-data-am/s/install-docDATA//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
