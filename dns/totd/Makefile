# New ports collection makefile for:   totd
# Date created:        17 Nov 2000
# Whom:                Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	totd
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	dns ipv6
MASTER_SITES=	ftp://ftp.pasta.cs.uit.no/pub/Vermicelli/

MAINTAINER=	ed@fxq.nl
COMMENT=	DNS proxy that supports IPv6 <==> IPv4 record translation

USE_RC_SUBR=	totd
GNU_CONFIGURE=	yes

MAN8=		totd.8
PLIST_FILES=	etc/totd.conf.sample sbin/totd

EXTRA_PATCHES=	${FILESDIR}/extra-patch-ne_mesg.c \
		${FILESDIR}/extra-patch-tcp_response.c

post-patch:
	@${REINPLACE_CMD} -e '/^CC/d' ${WRKSRC}/${MAKEFILE}.in

post-install:
	${INSTALL_DATA} ${FILESDIR}/totd.conf.sample ${PREFIX}/etc

.include <bsd.port.mk>
