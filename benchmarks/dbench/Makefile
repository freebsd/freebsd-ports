# New ports collection makefile for:	dbench
# Date created:		18 Febrary 2002
# Whom:			Andrew Shevtsov <nyxo@dnuc.polyn.kiae.su>
#
# $FreeBSD$
#

PORTNAME=	dbench
PORTVERSION=	3.04
CATEGORIES=	benchmarks
MASTER_SITES=	http://samba.org/ftp/tridge/dbench/

MAINTAINER=	jmelo@freebsdbrasil.com.br
COMMENT=	A simulation of the Ziff-Davis netbench benchmark

GNU_CONFIGURE=	yes

NOT_FOR_ARCHS=	amd64

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"Doesn't build on FreeBSD < 5.x"
.endif

.include <bsd.port.post.mk>
