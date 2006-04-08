# Ports collection makefile for:  impress
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	impress
PORTVERSION=	1.1b9
PORTREVISION=	1
CATEGORIES=	editors tk84
MASTER_SITES=	http://fresh.t-systems-sfr.com/unix/src/privat2/ \
		ftp://ftp.plig.net/pub/OpenBSD/distfiles/ \
		ftp://ftp.uni-stuttgart.de/pub/mirror/ftp.openbsd.org/pub/OpenBSD/distfiles/ \
		ftp://ftp.openoffice.pl/bsd/FreeBSD/ports/distfiles/
DISTNAME=	imp${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Publishing and presentation tool

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
