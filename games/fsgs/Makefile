# New ports collection makefile for:	fsgs
# Date created:		16 July 2001
# Whom:			Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	fsgs
PORTVERSION=	0.7.1.26
CATEGORIES=	games net
MASTER_SITES=	http://www.net-games.com/downloads/
DISTFILES=	fsgs07126bsd.tgz fsgs0721lx.tgz

MAINTAINER=	dburr@FreeBSD.ORG

NO_BUILD=	yes

IGNORE=		"Disabled for legal reasons"

do-install:
	${CP} -Rp ${WRKDIR}/opt/fsgs ${PREFIX}/fsgs
	${CP} ${WRKDIR}/release/fsgs ${PREFIX}/fsgs/fsgs
	${CP} ${WRKDIR}/release/fsgs_static ${PREFIX}/fsgs/fsgs_static
	${CHOWN} -R root:games ${PREFIX}/fsgs
	${CHMOD} 2711 ${PREFIX}/fsgs/fsgs ${PREFIX}/fsgs/fsgs_static
	${INSTALL_SCRIPT} ${FILESDIR}/fsgs.sh ${PREFIX}/etc/rc.d/fsgs.sh
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
