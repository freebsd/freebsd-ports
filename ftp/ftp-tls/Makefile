# Ports collection makefile for:	ftp-tls
# Date created:				24 October 2002
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$
#

PORTNAME=	ftp-tls
PORTVERSION=	20020906
CATEGORIES=	ftp security
MASTER_SITES=	ftp://ftp.runestig.com/pub/ftp-tls/

MAINTAINER=	marius@alchemy.franken.de

USE_AUTOCONF=	YES
GNU_CONFIGURE=	YES

USE_OPENSSL=	YES

MAN1=		ftp-tls.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
BROKEN=		"Not supported on systems prior to FreeBSD 4.0 (missing getaddrinfo())"
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ftp ${PREFIX}/bin/ftp-tls
	@${INSTALL_MAN} ${WRKSRC}/ftp.1.TLS ${PREFIX}/man/man1/ftp-tls.1

.include <bsd.port.post.mk>
