# Created by: Alexander Zhuravlev <zaa@zaa.pp.ru>
# $FreeBSD$

PORTNAME=	mysqlsla
PORTVERSION=	2.03
PORTREVISION=	3
CATEGORIES=	databases

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mysqlsla analyzes general, slow, and raw MySQL statement logs

LICENSE=	GPLv2+

RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey

NO_ARCH=	yes
USES=		perl5 shebangfix
WRKSRC_SUBDIR=	${PORTNAME}

PLIST_FILES=	bin/mysqlsla \
		man/man3/mysqlsla.3.gz

USE_GITHUB=	yes
GH_ACCOUNT=	daniel-nichter
GH_PROJECT=	hackmysql.com
GH_TAGNAME=	97e2d39

SHEBANG_FILES=	bin/mysqlsla

do-build:
	@pod2man ${WRKSRC}/lib/mysqlsla.pm > ${WRKSRC}/mysqlsla.3

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mysqlsla ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mysqlsla.3 ${STAGEDIR}${MAN3PREFIX}/man/man3

.include <bsd.port.mk>
