# Created by: lth@FreeBSD.org
# $FreeBSD$

PORTNAME=	sql-ledger
PORTVERSION=	3.0.6
CATEGORIES=	finance perl5
MASTER_SITES=	http://www.sql-ledger.com/source/ \
		http://abacus.sql-ledger.com/source/ \
		http://pluto.sql-ledger.com/source/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Double entry accounting system

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message sql-ledger-httpd.conf
USES=		shebangfix perl5
SHEBANG_FILES=	*.pl locale/*/*.pl bin/*/*.pl

do-install:
	cd ${WRKDIR} ; \
		${TAR} -cf - ${PORTNAME} | ( cd ${STAGEDIR}${PREFIX} ; ${TAR} xf - )
	cd ${STAGEDIR}${PREFIX}/${PORTNAME} ; \
		${CHMOD} 711 users templates css spool
	${INSTALL_DATA} ${WRKDIR}/sql-ledger-httpd.conf ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
