# New ports collection makefile for:	sql-ledger
# Date created:		2005-10-29
# Whom:			lth@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	sql-ledger
PORTVERSION=	2.6.11
CATEGORIES=	finance perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.sql-ledger.com/source/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A double entry accounting system

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
RUN_DEPENDS=	${BUILD_DEPENDS}

NO_BUILD=	yes
USE_PERL5=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PKGMESSAGE=	${WRKDIR}/pkg-message

post-patch:
	@${PERL} -pi -e 's|/usr/bin/perl|${PERL}|' \
		`${FIND} ${WRKSRC} -name \*.pl`
	@${PERL} -pe 's|%%PREFIX%%|${PREFIX}|g' \
		${FILESDIR}/sql-ledger-httpd.conf.in \
		> ${WRKDIR}/sql-ledger-httpd.conf
	@${PERL} -pe 's|%%PREFIX%%|${PREFIX}|g' \
		${PKGDIR}/pkg-message \
		> ${PKGMESSAGE}

do-install:
	@cd ${WRKDIR} ; \
		${TAR} -cf - ${PORTNAME} | ( cd ${PREFIX} ; ${TAR} xf - )
	@cd ${PREFIX}/${PORTNAME} ; \
		${CHOWN} -hR ${WWWOWN}:${WWWGRP} * ; \
		${CHMOD} 711 users templates css spool
	@${INSTALL_DATA} ${WRKDIR}/sql-ledger-httpd.conf ${PREFIX}/etc/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
