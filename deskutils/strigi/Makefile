# Created by: Tilman Keskinoz <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	strigi
PORTVERSION=	${STRIGI_VERSION}
PORTREVISION=	4
CATEGORIES=	deskutils

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Strigi desktop search (meta port)

USES=		kde:4 metaport
USE_KDE=	strigi_run

OPTIONS_DEFINE=	CLIENT DAEMON UTILITIES
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

.include <bsd.port.pre.mk>
.include <${.CURDIR}/Makefile.common>

.if ${PORT_OPTIONS:MCLIENT}
RUN_DEPENDS+=	${LOCALBASE}/bin/strigiclient:deskutils/strigiclient
.endif

.if ${PORT_OPTIONS:MDAEMON}
RUN_DEPENDS+=	${LOCALBASE}/bin/strigidaemon:deskutils/strigidaemon
.endif

.if ${PORT_OPTIONS:MUTILITIES}
RUN_DEPENDS+=	${LOCALBASE}/bin/xmlindexer:deskutils/strigiutils
.endif

.include <bsd.port.post.mk>
