# New ports collection makefile for:	xshttpd
# Date created:				9 September 2010
# Whom:					Johan van Selst <johans@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	algol68g
PORTVERSION=	2.3.2
CATEGORIES=	lang
MASTER_SITES=	http://jmvdveer.home.xs4all.nl/
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Alogol 68 Genie compiler

LIB_DEPENDS=	gsl.16:${PORTSDIR}/math/gsl

OPTIONS=	PLOT "GNU plot support" On \
		PGSQL "Postgresql support" On

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-compiler

MAN1=		a68g.1
PLIST_DIRS=	include/algol68g
PLIST_FILES=	bin/a68g include/algol68g/a68g.h

.include <bsd.port.options.mk>

.ifdef WITH_PLOT
LIB_DEPENDS+=	plot.4:${PORTSDIR}/graphics/plotutils
.else
CONFIGURE_ARGS+=--disable-plotutils
.endif

.ifdef WITH_PGSQL
USE_PGSQL=	yes
.else
CONFIGURE_ARGS+=--disable-postgresql
.endif

post-patch:
	# Skip broken check, assume our $CC works
	@${REINPLACE_CMD} -e 's/"xgcc"/"x${CC}"/' ${WRKSRC}/configure

.include <bsd.port.mk>
