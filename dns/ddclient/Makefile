# New ports collection makefile for:	ddclient
# Date created:		Sun Aug 26 14:45:12 CEST 2001
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ddclient
PORTVERSION=	3.6.7
CATEGORIES=	dns
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	radek@raadradd.com
COMMENT=	Update dynamic DNS entries

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes
USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
PLIST_FILES=	etc/ddclient.conf.sample sbin/ddclient

PORTDOCS=	COPYING COPYRIGHT Changelog README README.cisco \
		sample-etc_cron.d_ddclient sample-etc_dhclient-exit-hooks \
		sample-etc_dhcpc_dhcpcd-eth0.exe sample-etc_ppp_ip-up.local

post-patch:
	@${GREP} -lr '/usr' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g'
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|/usr.*perl|${PERL}|g' ${WRKSRC}/ddclient

do-install:
	@${INSTALL_DATA} ${WRKSRC}/sample-etc_ddclient.conf ${PREFIX}/etc/ddclient.conf.sample
	@${INSTALL_SCRIPT} ${WRKSRC}/ddclient ${PREFIX}/sbin/
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
