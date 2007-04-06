# New ports collection makefile for:	ftp-proxy
# Date created:        4. March 2007
# Whom:                Christian Ludwig
#
# $FreeBSD$
#

PORTNAME=	ftp-proxy
PORTVERSION=	4.0p0
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	http://www.chrissicool.net/projects/ftp-proxy/distfiles/

MAINTAINER=	chrissicool@chrissicool.net
COMMENT=	A port of OpenBSD's ftp-proxy

LIB_DEPENDS=	event-1.3b:${PORTSDIR}/devel/libevent

MAN8=		ftp-proxy.8
MANCOMPRESSED=	yes

PLIST_FILES=	sbin/ftp-proxy		\
		etc/rc.d/ftp-proxy.sh

CFLAGS+=	-I${PREFIX}/include

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ftp-proxy ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${FILESDIR}/ftp-proxy.sh ${PREFIX}/etc/rc.d
	${INSTALL_MAN} ${WRKSRC}/ftp-proxy.8.gz ${PREFIX}/man/man8

.include <bsd.port.mk>
