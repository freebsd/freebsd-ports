# New ports collection makefile for:	ledger-smb
# Date created:		2007-3-20
# Whom:			anarcat@anarcat.ath.cx
#
# $FreeBSD$
#

PORTNAME=	ledgersmb
PORTVERSION=	1.2.17
CATEGORIES=	finance perl5
MASTER_SITES=	SF/ledger-smb/${PORTNAME}/${PORTVERSION}

MAINTAINER=	anarcat@anarcat.ath.cx
COMMENT=	A double entry accounting system

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg \
			${SITE_PERL}/MIME/Lite.pm:${PORTSDIR}/mail/p5-MIME-Lite \
			${SITE_PERL}/Config/Std.pm:${PORTSDIR}/devel/p5-Config-Std
RUN_DEPENDS=	${BUILD_DEPENDS}

LATEST_LINK=	ledgersmb12

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
USE_PERL5=	yes

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

post-patch:
	@${PERL} -pi -e 's|/usr/bin/perl|${PERL}|' \
		`${FIND} ${WRKSRC} -name \*.pl`
	@${PERL} -pe 's|%%PREFIX%%|${PREFIX}|g' \
		${FILESDIR}/ledger-smb-httpd.conf.in \
		> ${WRKDIR}/ledger-smb-httpd.conf

do-install:
	@${CP} -R ${WRKSRC} ${PREFIX}
	@cd ${PREFIX}/${PORTNAME} ; \
		${CHOWN} -hR ${WWWOWN}:${WWWGRP} * ; \
		${CHMOD} 711 templates css spool
	@${INSTALL_DATA} ${WRKDIR}/ledger-smb-httpd.conf ${PREFIX}/etc/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
