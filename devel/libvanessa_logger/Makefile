# New ports collection makefile for:	libvanessa_logger
# Date created:		28 April 2001
# Whom:			Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	libvanessa_logger
PORTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://vanessa.sourceforge.net/pub/vanessa/%SUBDIR%/ \
		ftp://ftp.au.vergenet.net/pub/vanessa/%SUBDIR%/ \
		ftp://ftp.nl.vergenet.net/pub/vanessa/%SUBDIR%/ \
		ftp://ftp.jp.vergenet.net/pub/vanessa/%SUBDIR%/ \
		ftp://ftp.us.vergenet.net/pub/vanessa/%SUBDIR%/
MASTER_SITE_SUBDIR=	vanessa_logger/${PORTVERSION}
DISTNAME=	vanessa_logger-${PORTVERSION}

MAINTAINER=	kkonstan@daemon.gr

MAN1=		vanessa_logger_sample.1

INSTALLS_SHLIB= YES

USE_LIBTOOL=	YES
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
WRKSRC=		${WRKDIR}/vanessa_logger-${PORTVERSION}

.include <bsd.port.mk>
