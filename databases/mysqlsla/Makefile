# Created by: Alexander Zhuravlev <zaa@zaa.pp.ru>
# $FreeBSD$

PORTNAME=	mysqlsla
PORTVERSION=	2.03
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://hackmysql.com/scripts/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mysqlsla analyzes general, slow, and raw MySQL statement logs

LICENSE=	GPLv2 # or later

RUN_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey

USES=		perl5 shebangfix
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/mysqlsla \
		man/man3/mysqlsla.3.gz

SHEBANG_FILES=	bin/mysqlsla

pre-install:
	@${MKDIR} ${WRKSRC}/doc
	pod2man ${WRKSRC}/lib/mysqlsla.pm > ${WRKSRC}/doc/mysqlsla.3

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mysqlsla ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/mysqlsla.3 ${STAGEDIR}${MAN3PREFIX}/man/man3

.include <bsd.port.mk>
