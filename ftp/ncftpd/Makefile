# New ports collection Makefile for:	ncftpd
# Date created:		19 June 2001
# Whom:			Justin Stanford <jus@security.za.net>
#
# $FreeBSD$
#

PORTNAME=	ncftpd
PORTVERSION=	2.8.1
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.ncftp.com/ncftpd/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd${BINVER}-${ARCH}-export

MAINTAINER=	jus@security.za.net
COMMENT=	A well known commercial FTP daemon with a 30-day evaluation license

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

ONLY_FOR_ARCHS=	i386
NO_BUILD=	YES
LICENSE=	shareware
RESTRICTED=	"30 day evaluation license"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
BINVER=		5.2.1
.elif ${OSVERSION} >= 480000
BINVER=		4.8
.elif ${OSVERSION} >= 350000
BINVER=		3.5.1
.else
BROKEN=		"FreeBSD version too old"
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
	${INSTALL_SCRIPT} ${SCRIPTDIR}/ncftpd.sh ${PREFIX}/etc/rc.d

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ncftpd
	${INSTALL_DATA} ${WRKSRC}/install.html ${PREFIX}/share/doc/ncftpd
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ncftpd
	${INSTALL_DATA} ${WRKSRC}/README.freebsd ${PREFIX}/share/doc/ncftpd
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/ncftpd
.endif
	@${SED} -e 's,%%PREFIX%%,${PREFIX},' ${PKGMESSAGE}

.include <bsd.port.post.mk>
