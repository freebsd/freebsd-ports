# Created by: Tilman Keskinoz <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	strigi
PORTVERSION=	${STRIGI_VERSION}
PORTREVISION=	2
CATEGORIES=	deskutils
DISTFILES=      #

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Strigi desktop search (meta port)

USE_KDE4=	strigi_run
NO_BUILD=	yes
NO_MTREE=	yes

OPTIONS_DEFINE=	CLIENT DAEMON UTILITIES
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

.include <${.CURDIR}/Makefile.common>
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
RUN_DEPENDS+=	${LOCALBASE}/bin/strigiclient:${PORTSDIR}/deskutils/strigiclient
.endif

.if ${PORT_OPTIONS:MDAEMON}
RUN_DEPENDS+=	${LOCALBASE}/bin/strigidaemon:${PORTSDIR}/deskutils/strigidaemon
.endif

.if ${PORT_OPTIONS:MUTILITIES}
RUN_DEPENDS+=	${LOCALBASE}/bin/xmlindexer:${PORTSDIR}/deskutils/strigiutils
.endif

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
