# New ports collection makefile for:	openobex
# Date created:				15 March 2004
# Whom:					Guido Falsi <mad@madpilot.net>
#
# $FreeBSD$
#

PORTNAME=	openobex
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	comms net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mad@madpilot.net
COMMENT=	Open source implementation of the OBEX protocol

USE_AUTOTOOLS=	automake:14:env autoheader:253 autoconf:253 libtool:15
USE_GMAKE=		yes
INSTALLS_SHLIB=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--program-transform-name=""

.include <bsd.port.mk>
