# New ports collection makefile for:	ircd-hybrid
# Date Created:				2001-10-07
# Whom:					David Taylor <davidt@yadt.co.uk>
#
# $FreeBSD$
#

PORTNAME=	ircd-hybrid
PORTVERSION=	6.3
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ircd-hybrid
EXTRACT_SUFX=	.tgz

MAINTAINER=	davidt@yadt.co.uk

MAN8=		ircd.8

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.if !defined(PACKAGE_BUILDING) && !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

post-extract:
	@${MV} ${WRKSRC}/include/config.h ${WRKSRC}/include/config.h.in
	@${MV} ${WRKSRC}/tools/install_ircd ${WRKSRC}/tools/install_ircd.in

post-configure:
	${CHMOD} +x ${WRKSRC}/tools/install_ircd

pre-install:
.if !defined(PACKAGE_BUILDING) && !defined(BATCH)
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
.endif
	@${SED} -e "s#%PREFIX%#${PREFIX}#" ${FILESDIR}/ircd.sh \
		> ${WRKDIR}/ircd.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/ircd.sh ${PREFIX}/etc/rc.d
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
