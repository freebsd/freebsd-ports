# New ports collection makefile for:	pftpx
# Date created:		27 June 2005
# Whom:			Scott Ullrich (geekgod@geekgod.com)
#
# $FreeBSD$

PORTNAME=	pftpx
PORTVERSION=	0.8
PORTREVISION=	6
CATEGORIES=	ftp
MASTER_SITES=	http://www.sentia.org/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	sullrich@gmail.com
COMMENT=	Much enhanced ftp proxy for pf that supports most ftp protocols

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

MAN8=		pftpx.8

PLIST_FILES=	sbin/pftpx
USE_RC_SUBR=	pftpx

MAKE_ARGS=	LOCALBASE="${PREFIX}" OSLEVEL=37
CFLAGS+=	-DHAVE_ALTQ=1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pftpx ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/pftpx.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
