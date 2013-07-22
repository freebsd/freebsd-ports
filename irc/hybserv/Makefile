# Created by: Rick Fournier <rick@help-desk.ca>
# $FreeBSD$

PORTNAME=	hybserv
PORTVERSION=	1.9.5
CATEGORIES=	irc
MASTER_SITES=	GH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hybrid2 IRC Services

LICENSE=	GPLv2

OPTIONS_DEFINE=		DAEMONTOOLS
DAEMONTOOLS_DESC=	Daemontools support

USE_GITHUB=	yes
GH_ACCOUNT=	dkorunic
GH_PROJECT=	hybserv2
GH_TAGNAME=	REL_${PORTVERSION:S/./_/g}
GH_COMMIT=	ce15a9f

USES=		gmake
GNU_CONFIGURE=	yes

USERS=		${PORTNAME}
GROUPS=		${USERS}

DAEMONTOOLS_RUN_DEPENDS=	supervise:${PORTSDIR}/sysutils/daemontools
DAEMONTOOLS_CONFIGURE_ENABLE=	daemontools

.include <bsd.port.options.mk>

post-install:
	@${SED} -e "s#%PREFIX%#${PREFIX}#" ${FILESDIR}/hybserv.sh \
		> ${WRKDIR}/hybserv.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/hybserv.sh ${PREFIX}/etc/rc.d
	${CHOWN} -R hybserv:hybserv ${PREFIX}/hybserv
	${CHMOD} 700 ${PREFIX}/hybserv

.include <bsd.port.mk>
