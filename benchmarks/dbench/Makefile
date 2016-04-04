# Created by: Andrew Shevtsov <nyxo@dnuc.polyn.kiae.su>
# $FreeBSD$

PORTNAME=	dbench
PORTVERSION=	4.0
PORTREVISION=	2
CATEGORIES=	benchmarks
MASTER_SITES=	SAMBA/tridge/dbench

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Simulation of the Ziff-Davis netbench benchmark

LICENSE=	GPLv3

LIB_DEPENDS=	libpopt.so:devel/popt

CFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		autoreconf
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--datadir=${DATADIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
