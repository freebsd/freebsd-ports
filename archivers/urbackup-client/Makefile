# $FreeBSD$

PORTNAME=	urbackup-client
DISTVERSION=	2.2.6
CATEGORIES=	archivers
MASTER_SITES=	https://hndl.urbackup.org/Client/${DISTVERSION}/

MAINTAINER=	freebsd@coombscloud.com
COMMENT=	Client component of the UrBackup backup system

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcryptopp.so:security/cryptopp

USES=		gettext dos2unix localbase
USE_RC_SUBR=	urbackup_client

USERS=		urbackup
GROUPS=		urbackup

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-clientupdate

SUB_FILES=	pkg-message urbackupclient.conf.sample-daemon

WRKSRC=		${WRKDIR}/${DISTNAME}.0

OPTIONS_DEFINE=	GUI
OPTIONS_SUB=	yes

GUI_DESC=		GTK2 Tray Icon
GUI_USE=		WX=3.0+
GUI_CONFIGURE_ON=	--with-wx-config=${WX_CONFIG}
GUI_CONFIGURE_OFF=	--enable-headless

CONFFILES=	mariadbdump.conf \
		mariadbxtrabackup.conf \
		mariadbdump.conf \
		postgresbase.conf \
		postgresqldump.conf

XPMFILES=	backup-bad.xpm \
		backup-no-recent.xpm \
		backup-ok.xpm \
		backup-progress.xpm \
		backup-indexing.xpm \
		backup-no-server.xpm \
		backup-progress-pause.xpm

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/urbackup/scripts
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/urbackup
	${MKDIR} ${STAGEDIR}/var/urbackup/data
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d

	${INSTALL_PROGRAM} ${WRKSRC}/urbackupclientctl \
		${STAGEDIR}${PREFIX}/bin

	${INSTALL_PROGRAM} ${WRKSRC}/urbackupclientbackend \
		${STAGEDIR}${PREFIX}/sbin

	(cd ${WRKSRC}/urbackupclient/backup_scripts && 	${COPYTREE_BIN} . \
		${STAGEDIR}${PREFIX}/share/urbackup/scripts "! -name *\.conf")

	${INSTALL_DATA} ${WRKDIR}/urbackupclient.conf.sample-daemon \
		${STAGEDIR}${PREFIX}/etc/urbackup/urbackupclient.conf.sample

	${INSTALL_DATA} ${FILESDIR}/urbackupclient.conf-newsyslog \
		${STAGEDIR}${PREFIX}/etc/newsyslog.conf.d/urbackupclient.conf

.for f in ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/urbackupclient/backup_scripts/${f} \
		${STAGEDIR}${PREFIX}/etc/urbackup/${f}.sample
.endfor

	${INSTALL_DATA} ${WRKSRC}/client/data/updates_h.dat \
		${STAGEDIR}${PREFIX}/share/urbackup

	${INSTALL_MAN} ${WRKSRC}/docs/urbackupclientbackend.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

do-install-GUI-on:
	${INSTALL_PROGRAM} ${WRKSRC}/urbackupclientgui \
		${STAGEDIR}${PREFIX}/bin

	${INSTALL_DATA}	${WRKSRC}/client/data/logo1.png \
		${STAGEDIR}${PREFIX}/share/urbackup

	${INSTALL_DATA}	${WRKSRC}/client/info.txt \
		${STAGEDIR}${PREFIX}/share/urbackup

.for f in ${XPMFILES}
	${INSTALL_DATA} ${WRKSRC}/client/data/${f} \
		${STAGEDIR}${PREFIX}/share/urbackup
.endfor

.for f in it pl pt_BR sk zh_TW zh_CN de es fr ru uk da nl fa cs
	${MKDIR} ${STAGEDIR}${PREFIX}/share/urbackup/lang/${f}
.endfor

.for f in it pl pt_BR sk zh_TW zh_CN de es fr ru uk da nl fa cs
	${INSTALL_DATA} ${WRKSRC}/client/data/lang/${f}/urbackup.mo \
		${STAGEDIR}${PREFIX}/share/urbackup/lang/${f}
.endfor

.include <bsd.port.mk>
