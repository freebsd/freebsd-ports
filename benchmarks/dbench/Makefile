# New ports collection makefile for:	dbench
# Date created:		18 Febrary 2002
# Whom:			Andrew Shevtsov <nyxo@dnuc.polyn.kiae.su>
#
# $FreeBSD$
#

PORTNAME=	dbench
PORTVERSION=	3.04
PORTREVISION=	2
CATEGORIES=	benchmarks
MASTER_SITES=	http://samba.org/ftp/tridge/dbench/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simulation of the Ziff-Davis netbench benchmark

GNU_CONFIGURE=	yes

MAN1=	dbench.1
MLINKS=	dbench.1 tbench.1 dbench.1 tbench_srv.1

post-patch:
	@${REINPLACE_CMD} -e 's,$$(mandir),$$(mandir)/man1,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
