# Ports collection makefile for:	ftp-tls
# Date created:				24 October 2002
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$
#

PORTNAME=	ftp-tls
PORTVERSION=	20031008
CATEGORIES=	ftp security
MASTER_SITES=	ftp://ftp.zeist.de/pub/distfiles/ \
		ftp://ftp.runestig.com/pub/ftp-tls/

MAINTAINER=	marius@FreeBSD.org
COMMENT=	Ftp client supporting FTP AUTH TLS

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

MAN1=		ftp-tls.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
BROKEN=		"Not supported on systems prior to FreeBSD 4.0 (missing getaddrinfo())"
.endif

CONFIGURE_ARGS=		--with-openssl-dir=${OPENSSLBASE}
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ftp ${PREFIX}/bin/ftp-tls
	@${INSTALL_MAN} ${WRKSRC}/ftp.1.TLS ${PREFIX}/man/man1/ftp-tls.1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README.TLS draft-murray-auth-ftp-ssl-09.txt
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
