# New ports collection makefile for:	hybserv
# Date created:				15 Jan 2003
# Whom:					Rick Fournier <rick@help-desk.ca>
#
# $FreeBSD$
#

PORTNAME=	hybserv
PORTVERSION=	1.8.0
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://www.srce.hr/~kreator/projects/tarballs/

MAINTAINER=	rick@help-desk.ca
COMMENT=	"HybServ2 IRCD Services"

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/hybserv

.if !defined(PACKAGE_BUILDING) && !defined(BATCH)
IS_INTERACTIVE= yes
.endif

pre-install:
.if !defined(PACKAGE_BUILDING) && !defined(BATCH)
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

post-install:
	@${SED} -e "s#%PREFIX%#${PREFIX}#" ${FILESDIR}/hybserv.sh \
		> ${WRKDIR}/hybserv.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/hybserv.sh ${PREFIX}/etc/rc.d
	${CHOWN} -R hybserv:hybserv ${PREFIX}/hybserv
	${CHMOD} 700 ${PREFIX}/hybserv

.include <bsd.port.mk>
