PORTNAME=	dbench
PORTVERSION=	4.0
PORTREVISION=	3
CATEGORIES=	benchmarks
MASTER_SITES=	SAMBA/tridge/dbench

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simulation of the Ziff-Davis netbench benchmark
WWW=		https://dbench.samba.org/

LICENSE=	GPLv3

LIB_DEPENDS=	libpopt.so:devel/popt

CFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		autoreconf
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS+=--datadir=${DATADIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
