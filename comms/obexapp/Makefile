# New ports collection makefile for:	obexapp
# Date created:				22 March 2004
# Whom:					Guido Falsi <mad@madpilot.net>
#
# $FreeBSD$
#

PORTNAME=	obexapp
PORTVERSION=	1.4.4
CATEGORIES=	comms net
MASTER_SITES=	http://www.geocities.com/m_evmenkin/

MAINTAINER=	mad@madpilot.net
COMMENT=	Obex application to transfer objects to mobile equipment

LIB_DEPENDS=	openobex-1.0.1:${PORTSDIR}/comms/openobex

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_ICONV=	yes
MAN1=		obexapp.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/obexapp

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502101
IGNORE=		Needs 5.x from 20 Jan 2004 or later (sdpd)
.endif

.if ${OSVERSION} < 502121
# libbluetooth is only installed on i386 before this version
ONLY_FOR_ARCHS=	i386
.endif

.include <bsd.port.post.mk>
