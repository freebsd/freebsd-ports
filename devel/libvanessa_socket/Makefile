# New ports collection makefile for:	libvanessa_socket
# Date created:		28 April 2001
# Whom:			Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	libvanessa_socket
PORTVERSION=	0.0.3
CATEGORIES=	devel
MASTER_SITES=	ftp://vanessa.sourceforge.net/pub/vanessa/%SUBDIR%/ \
		ftp://ftp.au.vergenet.net/pub/vanessa/%SUBDIR%/ \
		ftp://ftp.nl.vergenet.net/pub/vanessa/%SUBDIR%/ \
		ftp://ftp.jp.vergenet.net/pub/vanessa/%SUBDIR%/ \
		ftp://ftp.us.vergenet.net/pub/vanessa/%SUBDIR%/
MASTER_SITE_SUBDIR=	vanessa_socket/${PORTVERSION}
DISTNAME=	vanessa_socket-${PORTVERSION}

MAINTAINER=	kkonstan@daemon.gr

LIB_DEPENDS=	vanessa_logger.0:${PORTSDIR}/devel/libvanessa_logger \
		popt.0:${PORTSDIR}/devel/popt

MAN1=		vanessa_socket_pipe.1

INSTALLS_SHLIB=	YES

USE_LIBTOOL=	YES
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
