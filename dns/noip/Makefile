# New ports collection makefile for:   No-IP Dynamic Update Client
# Date created:        28 March 2002
# Whom:                Eyal Soha <esoha@attbi.com>
#
# $FreeBSD$
#

PORTNAME=	noip
PORTVERSION=	1.6
CATEGORIES=	net
MASTER_SITES=	http://www.no-ip.com/client/linux/
DISTNAME=	noip_updater_v${PORTVERSION}

MAINTAINER=	esoha@attbi.com

ALL_TARGET=	noip

post-build:
	${SED} "s|%%PREFIX%%|${PREFIX}|g" < ${FILESDIR}/noip.sh > ${WRKSRC}/noip.sh

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/noip ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/noip.sh ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/README.FIRST ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/COPYING ${PREFIX}/share/doc/${PORTNAME}
	${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/no-ip.conf.sample ${PREFIX}/share/examples/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/no-ip.sh ${PREFIX}/share/examples/${PORTNAME}
.endif
	@${SED} "s|%%PREFIX%%|${PREFIX}|g" ${PKGMESSAGE} | ${SED} "s|%%WRKSRC%%|${WRKSRC}|g"

conf:
	(cd ${PREFIX}/etc && ${PREFIX}/share/examples/noip/no-ip.sh)
	${CHOWN} noip:noip ${PREFIX}/etc/no-ip.conf
	${CHMOD} 0600 ${PREFIX}/etc/no-ip.conf

.include <bsd.port.mk>
