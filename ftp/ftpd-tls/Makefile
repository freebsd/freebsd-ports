# Ports collection makefile for:	ftpd-tls
# Date created:				21 August 2003
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$
#

PORTNAME=	ftpd-tls
PORTVERSION=	20031008
PORTREVISION=	1
CATEGORIES=	ftp security
MASTER_SITES=	ftp://ftp.zeist.de/pub/distfiles/ \
		ftp://ftp.runestig.com/pub/ftpd-tls/

MAINTAINER=	marius@FreeBSD.org
COMMENT=	Ftp server supporting FTP AUTH TLS

GNU_CONFIGURE=	YES
USE_OPENSSL=	YES
USE_REINPLACE=	YES

MAN8=		ftpd-tls.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
BROKEN=		"Not supported on systems prior to FreeBSD 4.0 (missing getaddrinfo())"
.endif

CONFIGURE_ARGS=		--with-openssl-dir=${OPENSSLBASE}
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
PKGMESSAGE=		${WRKDIR}/pkg-message

post-patch:
.for i in README.TLS ftpd.8.TLS pathnames.h tlsutil.c
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/${i}
.endfor
	@${SED} 's|%%PREFIX%%|${PREFIX}|g; s|%%DOCSDIR%%|${DOCSDIR}|g' \
		${PKGDIR}/pkg-message > ${WRKDIR}/pkg-message
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/ftpd-tls.sh > \
		${WRKDIR}/ftpd-tls.sh

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ftpd ${PREFIX}/libexec/ftpd-tls
	@${INSTALL_MAN} ${WRKSRC}/ftpd.8.TLS ${PREFIX}/man/man8/ftpd-tls.8
	@${INSTALL_SCRIPT} ${WRKDIR}/ftpd-tls.sh \
		${PREFIX}/etc/rc.d/ftpd-tls.sh.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README.TLS draft-murray-auth-ftp-ssl-09.txt
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
.if !exists(${PREFIX}/etc/ftpd-tls)
	@${MKDIR} ${PREFIX}/etc/ftpd-tls
	@${CHMOD} 700 ${PREFIX}/etc/ftpd-tls
.endif
.if (!exists(${PREFIX}/etc/ftpd-tls/ftpusers)) && (exists(/etc/ftpusers))
	@${INSTALL_DATA} /etc/ftpusers ${PREFIX}/etc/ftpd-tls
.endif

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.post.mk>
