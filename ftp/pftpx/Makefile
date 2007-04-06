# New ports collection makefile for:	pftpx
# Date created:		27 June 2005
# Whom:			Scott Ullrich (geekgod@geekgod.com)
#
# $FreeBSD$

PORTNAME=	pftpx
PORTVERSION=	0.8
PORTREVISION=	3
CATEGORIES=	ftp
MASTER_SITES=	http://www.sentia.org/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	sullrich@gmail.com
COMMENT=	Much enhanced ftp proxy for pf that supports most ftp protocols

LIB_DEPENDS=	event-1.3b:${PORTSDIR}/devel/libevent

MAN8=		pftpx.8

PLIST_FILES=	sbin/pftpx
USE_RC_SUBR=	pftpx

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		only for 5.0 and above
.endif

.if ${OSVERSION} < 502116
MAKE_ARGS=	LOCALBASE="${PREFIX}" OSLEVEL=34
.if defined(WITH_ALTQ) && (${WITH_ALTQ} == "yes")
CFLAGS+=	-DHAVE_ALTQ=1
.endif
.elif ${OSVERSION} < 600025
MAKE_ARGS=	LOCALBASE="${PREFIX}" OSLEVEL=35
CFLAGS+=	-DHAVE_ALTQ=1 -DHAVE_RULE_ANCHOR=1
.else
MAKE_ARGS=	LOCALBASE="${PREFIX}" OSLEVEL=37
CFLAGS+=	-DHAVE_ALTQ=1
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pftpx ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pftpx.8 ${PREFIX}/man/man8

.include <bsd.port.post.mk>
