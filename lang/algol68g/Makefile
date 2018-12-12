# $FreeBSD$

PORTNAME=	algol68g
PORTVERSION=	2.8.4
PORTREVISION=	5
CATEGORIES=	lang
MASTER_SITES=	http://jmvdveer.home.xs4all.nl/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Algol 68 Genie compiler

LICENSE=	GPLv3+

LIB_DEPENDS=	libgsl.so:math/gsl

OPTIONS_DEFINE=	PLOTUTILS PGSQL
OPTIONS_DEFAULT=PLOTUTILS PGSQL

PLOTUTILS_DESC=		Plotting support via plotutils
PLOTUTILS_LIB_DEPENDS=	libplot.so:graphics/plotutils
PLOTUTILS_CONFIGURE_ENABLE=plotutils

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ENABLE=	postgresql

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-compiler
USES=		readline

PLIST_FILES=	bin/a68g man/man1/a68g.1.gz \
		include/algol68g/a68g.h include/algol68g/a68g-config.h

post-patch:
#	Skip broken check, assume our $CC works
	@${REINPLACE_CMD} -Ee 's/.*(\*-freebsd)/\1/' \
		-e 's|"xgcc"|"x${CC}"|; s/-ldl //' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^install-data-am/s/install-docDATA//' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
