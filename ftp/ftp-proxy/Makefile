# New ports collection makefile for:	ftp-proxy
# Date created:        4. March 2007
# Whom:                Christian Ludwig
#
# $FreeBSD$
#

PORTNAME=	ftp-proxy
PORTVERSION=	4.4p1
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	http://www.chrissicool.net/projects/ftp-proxy/distfiles/

MAINTAINER=	chrissicool@chrissicool.net
COMMENT=	A port of OpenBSD's ftp-proxy

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

MAN8=		ftp-proxy.8
MANCOMPRESSED=	yes

PLIST_FILES=	sbin/ftp-proxy
USE_RC_SUBR=	ftp-proxy

CFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 700048
IGNORE=		is a part of base for 7.0 and above
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ftp-proxy ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/ftp-proxy.8.gz ${PREFIX}/man/man8

.include <bsd.port.post.mk>
