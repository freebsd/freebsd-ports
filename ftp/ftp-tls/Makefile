# Ports collection makefile for:	ftp-tls
# Date created:				24 October 2002
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$
#

PORTNAME=	ftp-tls
PORTVERSION=	20030805
CATEGORIES=	ftp security
MASTER_SITES=	ftp://ftp.zeist.de/pub/distfiles/ \
		ftp://ftp.runestig.com/pub/ftp-tls/

MAINTAINER=	marius@alchemy.franken.de
COMMENT=	Ftp client supporting FTP AUTH TLS

GNU_CONFIGURE=	YES

#USE_OPENSSL=	YES

MAN1=		ftp-tls.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
BROKEN=		"Not supported on systems prior to FreeBSD 4.0 (missing getaddrinfo())"
.endif

.include "${PORTSDIR}/security/openssl/bsd.openssl.mk"

CONFIGURE_ARGS=		--with-openssl-dir=${OPENSSLBASE}
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ftp ${PREFIX}/bin/ftp-tls
	@${INSTALL_MAN} ${WRKSRC}/ftp.1.TLS ${PREFIX}/man/man1/ftp-tls.1

.include <bsd.port.post.mk>
