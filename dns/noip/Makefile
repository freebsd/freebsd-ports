# New ports collection makefile for:   No-IP Dynamic Update Client
# Date created:        28 March 2002
# Whom:                Eyal Soha <esoha@attbi.com>
#
# $FreeBSD$
#

PORTNAME=	noip
PORTVERSION=	2.1.7
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	http://www.no-ip.com/client/linux/

MAINTAINER=	kay.abendroth@raxion.net
COMMENT=	No-IP.com's dynamic DNS update client

ALL_TARGET=	noip2
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_RC_SUBR=	noip

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/noip2 ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.FIRST ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/COPYING ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

conf:
	(cd ${PREFIX}/etc && ${PREFIX}/bin/noip2 -C)
	${CHOWN} noip:noip ${PREFIX}/etc/no-ip2.conf
	${CHMOD} 0600 ${PREFIX}/etc/no-ip2.conf

.include <bsd.port.mk>
