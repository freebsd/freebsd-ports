# ex:ts=8
# New ports collection makefile for:	bonnie++
# Date created:			Mar 24, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bonnie++
PORTVERSION=	1.02c
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.coker.com.au/bonnie++/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Performance Test of Filesystem I/O

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-U__DEPRECATED"

MAN1=	bon_csv2html.1 bon_csv2txt.1
MAN8=	bonnie++.8 zcav.8

.include <bsd.port.mk>
