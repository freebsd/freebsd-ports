# Ports collection makefile for:	ftpd-tls
# Date created:				21 August 2003
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$
#

PORTNAME=	ftpd-tls
PORTVERSION=	20031008
PORTREVISION=	2
CATEGORIES=	ftp security
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	marius

MAINTAINER=	marius@FreeBSD.org
COMMENT=	Ftp server supporting FTP AUTH TLS

GNU_CONFIGURE=	YES
USE_OPENSSL=	YES
USE_RC_SUBR=	ftpd-tls

MAN8=		ftpd-tls.8

CONFIGURE_ARGS=		--with-openssl-dir=${OPENSSLBASE}
PKGMESSAGE=		${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

post-patch:
.for i in README.TLS ftpd.8.TLS pathnames.h tlsutil.c
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/${i}
.endfor
	@${SED} 's|%%PREFIX%%|${PREFIX}|g; s|%%DOCSDIR%%|${DOCSDIR}|g' \
		${PKGDIR}/pkg-message > ${WRKDIR}/pkg-message

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ftpd ${PREFIX}/libexec/ftpd-tls
	@${INSTALL_MAN} ${WRKSRC}/ftpd.8.TLS ${PREFIX}/man/man8/ftpd-tls.8
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

pre-install:
# Make sure there's no startup script left over from a previous installation.
	@${RM} -f ${PREFIX}/etc/rc.d/ftpd-tls.sh

post-install:
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.post.mk>
