# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ddclient
PORTVERSION=	3.8.2
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Update dynamic DNS entries

LICENSE=	GPLv2

NO_BUILD=	yes

USE_BZIP2=	yes
USES=		perl5
USE_PERL5=	run

USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-message ddclient_force

OPTIONS_DEFINE=	SSL
OPTIONS_DEFAULT=SSL

SSL_RUN_DEPENDS=ca_root_nss>0:${PORTSDIR}/security/ca_root_nss \
		p5-IO-Socket-SSL>0:${PORTSDIR}/security/p5-IO-Socket-SSL

PORTDOCS=	COPYRIGHT Changelog README.cisco README.ssl README.md \
		sample-etc_cron.d_ddclient sample-etc_dhclient-exit-hooks \
		sample-etc_dhcpc_dhcpcd-eth0.exe sample-etc_ppp_ip-up.local
PLIST_FILES=	etc/ddclient.conf.sample etc/periodic/daily/ddclient_force \
		sbin/ddclient
PLIST_DIRSTRY=	etc/periodic/daily etc/periodic

post-patch:
	@${GREP} -lR '/usr' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr|${PREFIX}|g'
	@${REINPLACE_CMD} -e \
		's|%%PERL%%|${PERL}| ; \
		 s|%%ETCDIR%%|${PREFIX}/etc| ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/ddclient

do-install:
	(cd ${WRKSRC} && ${INSTALL_DATA} sample-etc_ddclient.conf \
		${STAGEDIR}${PREFIX}/etc/ddclient.conf.sample)
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} ddclient \
		${STAGEDIR}${PREFIX}/sbin)
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	(cd ${WRKDIR} && ${INSTALL_SCRIPT} ddclient_force \
		${STAGEDIR}${PREFIX}/etc/periodic/daily/ddclient_force)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
