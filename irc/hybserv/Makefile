# Created by: Rick Fournier <rick@help-desk.ca>
# $FreeBSD$

PORTNAME=	hybserv
PORTVERSION=	1.9.5
CATEGORIES=	irc
MASTER_SITES=	GH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hybrid2 IRC Services

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	dkorunic
GH_PROJECT=	hybserv2
GH_TAGNAME=	REL_${PORTVERSION:S/./_/g}
GH_COMMIT=	ce15a9f

USES=		gmake
GNU_CONFIGURE=	yes

USERS=		${PORTNAME}
GROUPS=		${USERS}

OPTIONS_DEFINE=		DAEMONTOOLS

DAEMONTOOLS_DESC=		Daemontools support
DAEMONTOOLS_RUN_DEPENDS=	supervise:${PORTSDIR}/sysutils/daemontools
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
