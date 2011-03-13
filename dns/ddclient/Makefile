# New ports collection makefile for:	ddclient
# Date created:		Sun Aug 26 14:45:12 CEST 2001
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ddclient
PORTVERSION=	3.8.0
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	Update dynamic DNS entries

.ifndef WITHOUT_SSL
RUN_DEPENDS=	${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL
.endif

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes
USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-message ddclient_force
PKGMESSAGE=	${WRKDIR}/pkg-message

PORTDOCS=	COPYING COPYRIGHT Changelog README README.cisco README.ssl \
		sample-etc_cron.d_ddclient sample-etc_dhclient-exit-hooks \
		sample-etc_dhcpc_dhcpcd-eth0.exe sample-etc_ppp_ip-up.local

post-patch:
	@${GREP} -lr '/usr' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g'
	@${REINPLACE_CMD} \
		-e 's|/tmp|/var/tmp|' \
		-e 's|/var/cache/ddclient|/var/tmp|' \
		-e '/PATH/s|/etc:/usr/local/lib:||' \
		-e 's|/usr.*perl|${PERL}|g' \
		-e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|/etc/ddclient|${PREFIX}/etc|' \
		${WRKSRC}/ddclient

do-install:
	@${INSTALL_DATA} ${WRKSRC}/sample-etc_ddclient.conf ${PREFIX}/etc/ddclient.conf.sample
	@${INSTALL_SCRIPT} ${WRKSRC}/ddclient ${PREFIX}/sbin/
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

post-install:
	${MKDIR} ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/ddclient_force ${PREFIX}/etc/periodic/daily/ddclient_force
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
