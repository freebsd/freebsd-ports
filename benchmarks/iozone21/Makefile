# ex:ts=8
# Ports collection makefile for:  iozone
# Date created:			  26 September 1994
# Whom:				  jmz
#
# $FreeBSD$
#

PORTNAME=	iozone
PORTVERSION=	2.01
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.cs.uni-sb.de/pub/others/
EXTRACT_SUFX=	.shar.gz

MAINTAINER=	obrien@FreeBSD.org

LATEST_LINK=	iozone21

EXTRACT_CMD=	( gzcat | awk '{if (/^\#!/) x++} {if(x) print $$0'}| /bin/sh )
EXTRACT_BEFORE_ARGS=	<
EXTRACT_AFTER_ARGS=	# empty
NO_WRKSUBDIR=	YES
MAN1=		iozone.1

.include <bsd.port.mk>
