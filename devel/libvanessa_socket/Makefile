# New ports collection makefile for:	libvanessa_socket
# Date created:		28 April 2001
# Whom:			Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	libvanessa_socket
PORTVERSION=	0.0.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.vergenet.net/linux/vanessa/download/%SUBDIR%/
MASTER_SITE_SUBDIR=	vanessa_socket/${PORTVERSION}
DISTNAME=	vanessa_socket-${PORTVERSION}

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Library that provides a simple layer for TCP/IP socket operations

LIB_DEPENDS=	vanessa_logger.0:${PORTSDIR}/devel/libvanessa_logger \
		popt.0:${PORTSDIR}/devel/popt

MAN1=		vanessa_socket_pipe.1

INSTALLS_SHLIB=	YES

USE_LIBTOOL=	YES
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
