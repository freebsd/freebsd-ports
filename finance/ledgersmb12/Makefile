# Created by: anarcat@anarcat.ath.cx
# $FreeBSD$

PORTNAME=	ledgersmb
PORTVERSION=	1.2.26
CATEGORIES=	finance perl5
MASTER_SITES=	http://download.ledgersmb.org/f/Releases/archive-1.2/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Double entry accounting system

BUILD_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg \
		p5-MIME-Lite>=0:mail/p5-MIME-Lite \
		p5-Config-Std>=0:devel/p5-Config-Std
RUN_DEPENDS:=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	utils/devel/chart-load-test.sh \
		utils/devel/find-use \
		utils/pos/pos-hardware-client-startup-script
USE_PERL5=	run build patch
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|/usr/bin/perl|${perl_CMD}|' \
		`${FIND} ${WRKSRC} -name \*.pl`
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${FILESDIR}/ledger-smb-httpd.conf.in \
		> ${WRKDIR}/ledger-smb-httpd.conf

do-install:
	@${CP} -R ${WRKSRC} ${STAGEDIR}${PREFIX}
	@cd ${STAGEDIR}${PREFIX}/${PORTNAME} ; \
		${CHMOD} 711 templates css spool
	${INSTALL_DATA} ${WRKDIR}/ledger-smb-httpd.conf ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
