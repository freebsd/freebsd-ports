# New ports collection makefile for:	downloader
# Date Created:		23 June 1999
# Whom:			Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	downloader
PORTVERSION=	1.11
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.server51.freshmeat.net/pub/d4x/ \
		ftp://ftp.lonyay.edu.hu/pub/software/nt/ \
		http://people.FreeBSD.org/~imura/distfiles/
DISTNAME=	nt-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

WRKSRC=		${WRKDIR}/${DISTNAME}/main

CFLAGS=		-pedantic

.include <bsd.port.mk>
