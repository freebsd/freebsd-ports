# New ports collection makefile for:	ddclient
# Date created:		Sun Aug 26 14:45:12 CEST 2001
# Whom:			Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ddclient
PORTVERSION=	3.6.3
CATEGORIES=	dns
MASTER_SITES=	http://members.rogers.com/ddclient/pub/

MAINTAINER=	dirk@FreeBSD.org
COMMENT=	Update dynamic DNS entries

USE_PERL5=	yes
NO_BUILD=	yes

do-install:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g; s|%%PERL%%|${PERL}|g' ${WRKSRC}/ddclient
	@${INSTALL_SCRIPT} ${WRKSRC}/ddclient ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/sample-etc_ddclient.conf ${PREFIX}/etc/ddclient.conf.sample
	@${MKDIR} ${PREFIX}/share/ddclient
.for i in COPYING COPYRIGHT README README.cisco sample-etc_cron.d_ddclient \
	sample-etc_dhclient-exit-hooks sample-etc_dhcpc_dhcpcd-eth0.exe \
	sample-etc_ppp_ip-up.local
	@${PERL} -pe 's|%%PREFIX%%|${PREFIX}|g' < ${WRKSRC}/$i > ${WRKDIR}/$i
	@${INSTALL_DATA} ${WRKDIR}/$i ${PREFIX}/share/ddclient
.endfor
	@${PERL} -pe 's|%%PREFIX%%|${PREFIX}|g' < ${FILESDIR}/ddclient.sh.sample > ${WRKDIR}/ddclient.sh.sample
	@${INSTALL_SCRIPT} ${WRKDIR}/ddclient.sh.sample ${PREFIX}/etc/rc.d

	@${PERL} -pe 's|/usr/local|${PREFIX}|g' < ${PKGMESSAGE}

.include <bsd.port.mk>
