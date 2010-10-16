# New ports collection makefile for:	dbench
# Date created:		18 Febrary 2002
# Whom:			Andrew Shevtsov <nyxo@dnuc.polyn.kiae.su>
#
# $FreeBSD$
#

PORTNAME=	dbench
PORTVERSION=	4.0
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	SAMBA
MASTER_SITE_SUBDIR=	../../ftp/tridge/dbench

MAINTAINER=	kimelto@gmail.com
COMMENT=	A simulation of the Ziff-Davis netbench benchmark

LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt

LICENSE=	GPLv3

CFLAGS+=	-I${LOCALBASE}/include
USE_AUTOTOOLS=	autoconf:268
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=--datadir=${DATADIR}

MAN1=		dbench.1
MLINKS=		dbench.1 tbench.1 dbench.1 tbench_srv.1

post-patch:
	@${REINPLACE_CMD} -e 's,$$(mandir),$$(mandir)/man1,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
