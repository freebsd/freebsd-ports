# New ports collection makefile for:	hybserv
# Date created:				15 Jan 2003
# Whom:					Rick Fournier <rick@help-desk.ca>
#
# $FreeBSD$
#

PORTNAME=	hybserv
PORTVERSION=	1.9.1
CATEGORIES=	irc
MASTER_SITES=	http://www.hybserv.net/downloads/

MAINTAINER=	laszlof@vonostingroup.com
COMMENT=	HybServ2 IRCD Services

# uses a uid registered to the ircservices user
CONFLICT=	ircservices-*

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/hybserv

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${SED} -e "s#%PREFIX%#${PREFIX}#" ${FILESDIR}/hybserv.sh \
		> ${WRKDIR}/hybserv.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/hybserv.sh ${PREFIX}/etc/rc.d
	${CHOWN} -R hybserv:hybserv ${PREFIX}/hybserv
	${CHMOD} 700 ${PREFIX}/hybserv

.include <bsd.port.mk>
