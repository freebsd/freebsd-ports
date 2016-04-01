# Created by: Rick Fournier <rick@help-desk.ca>
# $FreeBSD$

PORTNAME=	hybserv
DISTVERSIONPREFIX=	REL_
DISTVERSION=	1_9_5
CATEGORIES=	irc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hybrid2 IRC Services

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	dkorunic
GH_PROJECT=	${PORTNAME}2

USES=		gmake
GNU_CONFIGURE=	yes

USERS=		${PORTNAME}
GROUPS=		${USERS}

OPTIONS_DEFINE=		DAEMONTOOLS

DAEMONTOOLS_DESC=		Daemontools support
DAEMONTOOLS_RUN_DEPENDS=	supervise:sysutils/daemontools
DAEMONTOOLS_CONFIGURE_ENABLE=	daemontools

post-patch:
	@${REINPLACE_CMD} -E -e '/(LN)/ s,BINDIR),DESTDIR)$$(&,2' \
		-e '/(LN)/! s,(BIN|CONF|DOC|HELP|LOG)DIR),DESTDIR)$$(&,' \
		${WRKSRC}/Makefile.in

post-install:
	@${SED} -e "s#%PREFIX%#${PREFIX}#" ${FILESDIR}/hybserv.sh \
		> ${WRKDIR}/hybserv.sh
	${INSTALL_SCRIPT} ${WRKDIR}/hybserv.sh ${STAGEDIR}${PREFIX}/etc/rc.d
	${CHMOD} 700 ${STAGEDIR}${PREFIX}/hybserv
	(cd ${STAGEDIR}${PREFIX}/hybserv && ${STRIP_CMD} hybserv mkpasswd \
		encryptconf encryptdb)

.include <bsd.port.mk>
