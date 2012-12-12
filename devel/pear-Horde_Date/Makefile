# Ports collection makefile for:  pear-Horde_Date
# Date created:			  6 July 2011
# Whom:				  Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Horde_Date
PORTVERSION=	2.0.1
CATEGORIES=	devel www pear

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Date package

USE_HORDE_RUN=	Horde_Exception \
		Horde_Nls \
		Horde_Translation

OPTIONS_DEFINE=	CALENDAR
CALENDAR_DESC=	Depend on calendar PHP extension

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MSOCKETS}
USE_PHP+=	calendar
.endif

.include "${PORTSDIR}/devel/pear-channel-horde/bsd.horde.mk"
.include <bsd.port.post.mk>
