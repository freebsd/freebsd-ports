# New ports collection makefile for:	ledger-smb
# Date created:		2007-3-20
# Whom:			anarcat@anarcat.ath.cx
#
# $FreeBSD$
#

PORTNAME=	ledger-smb
PORTVERSION=	1.1.12
PORTREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	SF/${PORTNAME}/ledgersmb/${PORTVERSION}

MAINTAINER=	anarcat@anarcat.ath.cx
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
		${FILESDIR}/${PORTNAME}-httpd.conf.in \
		> ${WRKDIR}/${PORTNAME}-httpd.conf
	@${PERL} -pe 's|%%PREFIX%%|${PREFIX}|g' \
		${PKGDIR}/pkg-message \
		> ${PKGMESSAGE}

do-install:
	@cd ${WRKDIR} ; \
		${TAR} -cf - ${PORTNAME} | ( cd ${PREFIX} ; ${TAR} xf - )
	@cd ${PREFIX}/${PORTNAME} ; \
		${CHOWN} -hR ${WWWOWN}:${WWWGRP} * ; \
		${CHMOD} 711 users templates css spool
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-httpd.conf ${PREFIX}/etc/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
