# Created by: lth@FreeBSD.org
# $FreeBSD$

PORTNAME=	sql-ledger
PORTVERSION=	3.0.8
CATEGORIES=	finance perl5
MASTER_SITES=	http://www.sql-ledger.com/source/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Double entry accounting system

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	pkg-message sql-ledger-httpd.conf
USES=		shebangfix perl5 pgsql
SHEBANG_FILES=	*.pl locale/*/*.pl bin/*/*.pl

do-install:
	cd ${WRKDIR} ; \
		${TAR} -cf - ${PORTNAME} | ( cd ${STAGEDIR}${PREFIX} ; ${TAR} xf - )
	${INSTALL_DATA} ${WRKDIR}/sql-ledger-httpd.conf ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
