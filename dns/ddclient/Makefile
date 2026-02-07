PORTNAME=	ddclient
DISTVERSIONPREFIX=	v
DISTVERSION=	4.0.0
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
USE_GITHUB=	yes
USE_PERL5=	run
USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes

NO_ARCH=	yes
SUB_FILES=	${PORTNAME}_force pkg-message

PORTDOCS=	COPYRIGHT ChangeLog README.cisco README.md \
		sample-etc_cron.d_ddclient sample-etc_dhclient-exit-hooks \
		sample-etc_dhcpc_dhcpcd-eth0.exe sample-etc_ppp_ip-up.local

OPTIONS_DEFINE=	DOCS

post-patch:
	@${GREP} -lR '/usr' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr|${PREFIX}|g'
	@${REINPLACE_CMD} -e 's|%%ETCDIR%%|${ETCDIR}| ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/${PORTNAME}.in

do-install:
	${MKDIR} ${STAGEDIR}${ETCDIR} \
		 ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}_force ${STAGEDIR}${PREFIX}/etc/periodic/daily

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
