# New ports collection makefile for:	ircd-hybrid
# Date Created:				2001-10-07
# Whom:					David Taylor <davidt@yadt.co.uk>
#
# $FreeBSD$
#

PORTNAME=	ircd-hybrid
PORTVERSION=	6.2
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ircd-hybrid
EXTRACT_SUFX=	.tgz

MAINTAINER=	davidt@yadt.co.uk

MAN8=		ircd.8

PATCH_STRIP=	-p1
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
PLIST_SUB=	PORTNAME=${PORTNAME}

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
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}/old
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}/old/US-Admin
	for i in old/US-Admin/Networking old/US-Admin/Operators \
		old/US-Admin/README old/Authors old/Etiquette old/README \
		CIDR.txt INDEX Makefile README.TSora Tao-of-IRC.940110 \
		blalloc.txt example.conf example.conf.trillian ircd.8 \
		mtrie.txt operguide.txt opermyth.txt rfc1459.txt \
		server-version-info simple.conf ts5.txt yline.txt; do \
	  ${INSTALL_MAN} ${WRKSRC}/doc/$$i \
	  	${PREFIX}/share/doc/${PORTNAME}/$$i; \
	done
.endif
	@${SED} -e "s#%PREFIX%#${PREFIX}#" ${FILESDIR}/ircd.sh \
		> ${WRKDIR}/ircd.sh
	@${INSTALL_SCRIPT} ${WRKDIR}/ircd.sh ${PREFIX}/etc/rc.d
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
