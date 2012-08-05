# New ports collection Makefile for:	ncftpd
# Date created:		19 June 2001
# Whom:			Justin Stanford <jus@security.za.net>
#
# $FreeBSD$
#

PORTNAME=	ncftpd
PORTVERSION=	2.8.7
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.ncftp.com/ncftpd/${PORTVERSION}/ \
		ftp://ftp.nl.uu.net/pub/unix/ftp/ncftpd/${PORTVERSION}/ \
		LOCAL/beech
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd${BINVER}-${DIST_ARCH}-export

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Commercial FTP daemon with a 30-day evaluation license

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	YES
RESTRICTED=	30 day evaluation license

USE_RC_SUBR=	ncftpd
SUB_FILES=	pkg-message

PORTDOCS=	install.html README README.freebsd LICENSE

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BINVER=		9.0
IGNORE=		not yet available for 9.x
.elif ${OSVERSION} >= 800000
BINVER=		8.0
.else
BINVER=		7.0
.endif

.if ${ARCH} == amd64
DIST_ARCH=	x86_64
.else
DIST_ARCH=	i386
.endif

do-install:
	${MKDIR} ${PREFIX}/etc/ncftpd
	${INSTALL_PROGRAM} ${WRKSRC}/ncftpd ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ncftpd_edquota ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ncftpd_passwd ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ncftpd_repquota ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ncftpd_spy ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/conf/general.cf-dist ${PREFIX}/etc/ncftpd
	${INSTALL_DATA} ${WRKSRC}/conf/domain.cf-dist ${PREFIX}/etc/ncftpd

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@ cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
