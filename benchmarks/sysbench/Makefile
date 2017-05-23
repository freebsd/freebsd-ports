# Created by: Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	sysbench
PORTVERSION=	0.5
CATEGORIES=	benchmarks databases

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular, cross-platform, and multi-threaded benchmark tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	akopytov
GH_TAGNAME=	a099b20

USES=		autoreconf libtool lua
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	LARGEFILE MYSQL PGSQL DOCS
OPTIONS_DEFAULT=	LARGEFILE MYSQL

LARGEFILE_DESC=			Largefile support
LARGEFILE_CONFIGURE_ENABLE=	largefile

MYSQL_CONFIGURE_ON=	--with-mysql
MYSQL_CONFIGURE_OFF=	--without-mysql
MYSQL_USES=	mysql

PGSQL_CONFIGURE_ON=	--with-pgsql
PGSQL_USES=	pgsql

post-configure:
	@${REINPLACE_CMD} -e 's/^program_transform_name/#/' \
	${WRKSRC}/Makefile ${WRKSRC}/sysbench/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/tests
	(cd ${WRKSRC}/sysbench/tests && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/tests)

.include <bsd.port.mk>
