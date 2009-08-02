# New ports collection makefile for:	libvanessa_socket
# Date created:		28 April 2001
# Whom:			Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	libvanessa_socket
PORTVERSION=	0.0.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.vergenet.net/linux/vanessa/download/%SUBDIR%/
MASTER_SITE_SUBDIR=	vanessa_socket/${PORTVERSION}
DISTNAME=	vanessa_socket-${PORTVERSION}

MAINTAINER=	thomas@bsdunix.ch
COMMENT=	Library that provides a simple layer for TCP/IP socket operations

LIB_DEPENDS=	vanessa_logger.0:${PORTSDIR}/devel/libvanessa_logger \
		popt.0:${PORTSDIR}/devel/popt

MAN1=		vanessa_socket_pipe.1

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
