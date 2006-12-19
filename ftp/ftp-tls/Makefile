# Ports collection makefile for:	ftp-tls
# Date created:				24 October 2002
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$
#

PORTNAME=	ftp-tls
PORTVERSION=	20051021
CATEGORIES=	ftp security
MASTER_SITES=	http://www.ford-hutchinson.com/~fh-1-pfh/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	marius

MAINTAINER=	marius@FreeBSD.org
COMMENT=	Ftp client supporting FTP AUTH TLS

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

MAN1=		ftp-tls.1

CONFIGURE_ARGS=		--with-openssl-dir=${OPENSSLBASE}
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
BROKEN=		Not supported on systems prior to FreeBSD 4.0 (missing getaddrinfo())
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ftp ${PREFIX}/bin/ftp-tls
	@${INSTALL_MAN} ${WRKSRC}/ftp.1.TLS ${PREFIX}/man/man1/ftp-tls.1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README.TLS draft-murray-auth-ftp-ssl-16.txt
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
