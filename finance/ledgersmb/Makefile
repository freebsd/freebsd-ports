# Created by: anarcat@anarcat.ath.cx
# $FreeBSD$

PORTNAME=	ledger-smb
PORTVERSION=	1.1.12
PORTREVISION=	1
CATEGORIES=	finance perl5
MASTER_SITES=	SF/${PORTNAME}/ledgersmb/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Double entry accounting system

BUILD_DEPENDS=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
PKGMESSAGE=	${WRKDIR}/pkg-message
USES=		shebangfix perl5
SHEBANG_FILES=	*.pl locale/*/*.pl bin/*/*.pl utils/*/*.pl
SUB_FILES=	${PORTNAME}-httpd.conf pkg-message

do-install:
	@cd ${WRKDIR} ; \
		${TAR} -cf - ${PORTNAME} | ( cd ${STAGEDIR}${PREFIX} ; ${TAR} xf - )
	@cd ${STAGEDIR}${PREFIX}/${PORTNAME} ; \
		${CHOWN} -hR ${WWWOWN}:${WWWGRP} * ; \
		${CHMOD} 711 users templates css spool
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}-httpd.conf ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
