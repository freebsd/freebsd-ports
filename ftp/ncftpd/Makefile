# Created by: Justin Stanford <jus@security.za.net>
# $FreeBSD$

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
BROKEN_i386=	Unfetchable
NO_BUILD=	YES
RESTRICTED=	30 day evaluation license

USE_RC_SUBR=	ncftpd
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

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
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/ncftpd
	${INSTALL_PROGRAM} ${WRKSRC}/ncftpd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/ncftpd_edquota ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ncftpd_passwd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ncftpd_repquota ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ncftpd_spy ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/conf/general.cf-dist ${STAGEDIR}${PREFIX}/etc/ncftpd
	${INSTALL_DATA} ${WRKSRC}/conf/domain.cf-dist ${STAGEDIR}${PREFIX}/etc/ncftpd

post-install:
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.post.mk>
