# New ports collection makefile for:	ddclient
# Date created:		Sun Aug 26 14:45:12 CEST 2001
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ddclient
PORTVERSION=	3.6.6
CATEGORIES=	dns
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	radek@raadradd.com
COMMENT=	Update dynamic DNS entries

USE_BZIP2=	yes
USE_PERL5=	yes
NO_BUILD=	yes
USE_RC_SUBR=	yes

PLIST_FILES=    etc/ddclient.conf.sample \
		etc/rc.d/ddclient.sh \
		sbin/ddclient

PORTDOCS=	COPYING COPYRIGHT Changelog README README.cisco \
		sample-etc_cron.d_ddclient sample-etc_dhclient-exit-hooks \
		sample-etc_dhcpc_dhcpcd-eth0.exe sample-etc_ppp_ip-up.local

post-patch:
	@${PERL} -pi -e 's|/etc/ddclient/|${PREFIX}/etc/ddclient/|g' ${WRKSRC}/README

do-install:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g; s|%%PERL%%|${PERL}|g' ${WRKSRC}/ddclient
	@${PERL} -pe 's|%%PREFIX%%|${PREFIX}|g; s|%%RC_SUBR%%|${RC_SUBR}|g' \
		< ${FILESDIR}/ddclient.sh > ${WRKDIR}/ddclient.sh
	@${INSTALL_DATA} ${WRKSRC}/sample-etc_ddclient.conf ${PREFIX}/etc/ddclient.conf.sample
	@${INSTALL_SCRIPT} ${WRKSRC}/ddclient ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKDIR}/ddclient.sh ${PREFIX}/etc/rc.d/

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${PERL} -pe 's|%%PREFIX%%|${PREFIX}|g' < ${WRKSRC}/$i > ${WRKDIR}/$i
	@${INSTALL_DATA} ${WRKDIR}/${i} ${DOCSDIR}
.endfor
.endif
	@${PERL} -pe 's|/usr/local|${PREFIX}|g' < ${PKGMESSAGE}

.include <bsd.port.mk>
