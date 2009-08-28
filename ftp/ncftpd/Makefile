# New ports collection Makefile for:	ncftpd
# Date created:		19 June 2001
# Whom:			Justin Stanford <jus@security.za.net>
#
# $FreeBSD$
#

PORTNAME=	ncftpd
PORTVERSION=	2.8.5
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
LICENSE=	shareware
RESTRICTED=	30 day evaluation license

USE_RC_SUBR=	ncftpd.sh
SUB_FILES=	pkg-message

PORTDOCS=	install.html README README.freebsd LICENSE

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000
BINVER=		7.0
.else
BINVER=		6.0
.endif

.if ${ARCH} == amd64
DIST_ARCH=	x86_64
.if ${BINVER} == "6.0"
BINVER=		6.2
.endif
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
