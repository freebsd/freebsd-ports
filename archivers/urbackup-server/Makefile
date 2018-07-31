# $FreeBSD$

PORTNAME=	urbackup-server
DISTVERSION=	2.2.11
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	https://hndl.urbackup.org/Server/${DISTVERSION}/

MAINTAINER=	freebsd@coombscloud.com
COMMENT=	Server component of the UrBackup backup system

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/server-license.txt

LIB_DEPENDS=	libcryptopp.so:security/cryptopp \
			libcurl.so:ftp/curl

USES+=		fakeroot

USERS=		urbackup
GROUPS=		urbackup

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--enable-packaging

USE_RC_SUBR=	urbackup_server

SUB_FILES=	pkg-message urbackupsrv.conf.sample-daemon

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/urbackup
	${INSTALL_DATA} ${WRKDIR}/urbackupsrv.conf.sample-daemon \
		${STAGEDIR}${PREFIX}/etc/urbackup/urbackupsrv.conf.sample
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d
	${INSTALL_DATA} ${FILESDIR}/urbackupsrv.conf.sample-newsyslog \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/urbackupsrv.conf.sample

	${INSTALL_MAN} ${WRKSRC}/docs/urbackupsrv.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
