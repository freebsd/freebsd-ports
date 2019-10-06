# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ddclient
DISTVERSIONPREFIX=	v
DISTVERSION=	3.8.3-104
DISTVERSIONSUFFIX=	-gec2acfb
PORTREVISION=	2
CATEGORIES=	dns

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Update dynamic DNS entries

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-Data-Validate-IP>0:net-mgmt/p5-Data-Validate-IP

USES=		perl5 tar:bzip2
USE_GITHUB=	yes
USE_PERL5=	run
USE_RC_SUBR=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message ddclient_force

OPTIONS_DEFINE=	SSL DOCS
OPTIONS_DEFAULT=SSL

SSL_RUN_DEPENDS=ca_root_nss>0:security/ca_root_nss \
		p5-IO-Socket-SSL>0:security/p5-IO-Socket-SSL

PORTDOCS=	COPYRIGHT ChangeLog README.cisco README.ssl README.md \
		sample-etc_cron.d_ddclient sample-etc_dhclient-exit-hooks \
		sample-etc_dhcpc_dhcpcd-eth0.exe sample-etc_ppp_ip-up.local
PLIST_FILES=	"@sample(,,600) etc/ddclient.conf.sample" etc/periodic/daily/ddclient_force \
		sbin/ddclient

post-patch:
	@${GREP} -lR '/usr' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr|${PREFIX}|g'
	@${REINPLACE_CMD} -e 's|%%ETCDIR%%|${PREFIX}/etc| ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/ddclient
	@${REINPLACE_CMD} -e '/^\#\!\/usr\/local\/local/d' \
		${WRKSRC}/ddclient

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
