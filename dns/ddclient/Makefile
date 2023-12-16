PORTNAME=	ddclient
DISTVERSIONPREFIX=	v
DISTVERSION=	3.11.2
CATEGORIES=	dns

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Update dynamic DNS entries
WWW=		https://github.com/ddclient/ddclient

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	curl:ftp/curl
RUN_DEPENDS=	p5-Data-Validate-IP>0:net-mgmt/p5-Data-Validate-IP \
		curl:ftp/curl

USES=		autoreconf gmake perl5 tar:bzip2
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
USE_PERL5=	run
USE_RC_SUBR=	${PORTNAME}

NO_ARCH=	yes
SUB_FILES=	pkg-message ddclient_force

PORTDOCS=	COPYRIGHT ChangeLog README.cisco README.md \
		sample-etc_cron.d_ddclient sample-etc_dhclient-exit-hooks \
		sample-etc_dhcpc_dhcpcd-eth0.exe sample-etc_ppp_ip-up.local

OPTIONS_DEFINE=	DOCS

post-patch:
	@${GREP} -lR '/usr' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr|${PREFIX}|g'
	@${REINPLACE_CMD} -e 's|%%ETCDIR%%|${PREFIX}/etc| ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/ddclient.in

do-install:
	(cd ${WRKSRC} && ${INSTALL_DATA} ddclient.conf \
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
