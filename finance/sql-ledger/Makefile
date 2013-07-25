# Created by: lth@FreeBSD.org
# $FreeBSD$

PORTNAME=	sql-ledger
PORTVERSION=	3.0.4
CATEGORIES=	finance perl5
MASTER_SITES=	http://www.sql-ledger.com/source/ \
		http://abacus.sql-ledger.com/source/ \
		http://pluto.sql-ledger.com/source/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	A double entry accounting system

BUILD_DEPENDS=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_BUILD=	yes
USE_PERL5=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message sql-ledger-httpd.conf
USES=		shebangfix
SHEBANG_FILES=	*.pl locale/*/*.pl bin/*/*.pl

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
