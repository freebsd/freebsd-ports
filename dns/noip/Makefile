# New ports collection makefile for:   No-IP Dynamic Update Client
# Date created:        28 March 2002
# Whom:                Eyal Soha <esoha@attbi.com>
#
# $FreeBSD$
#

PORTNAME=	noip
PORTVERSION=	2.1.1
CATEGORIES=	dns
MASTER_SITES=	http://www.no-ip.com/client/linux/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	No-IP.com's dynamic DNS update client

ALL_TARGET=	noip2

post-build:
	${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/noip.sh > ${WRKSRC}/noip.sh

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/noip2 ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/noip.sh ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.FIRST ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/COPYING ${DOCSDIR}
.endif
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" ${PKGMESSAGE} | ${SED} "s|%%WRKSRC%%|${WRKSRC}|g"

conf:
	(cd ${PREFIX}/etc && ${PREFIX}/bin/noip2 -C)
	${CHOWN} noip:noip ${PREFIX}/etc/no-ip2.conf
	${CHMOD} 0600 ${PREFIX}/etc/no-ip2.conf

.include <bsd.port.mk>
