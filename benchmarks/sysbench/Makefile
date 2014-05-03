# Created by: Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	sysbench
PORTVERSION=	0.4.12
PORTREVISION=	2
CATEGORIES=	benchmarks databases
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular, cross-platform, and multi-threaded benchmark tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_AUTOTOOLS=	libtool

PLIST_FILES=	bin/sysbench
PORTDOCS=	manual.html

OPTIONS_DEFINE=	LARGEFILE MYSQL PGSQL DOCS
OPTIONS_DEFAULT=	LARGEFILE MYSQL

LARGEFILE_DESC=			Largefile support
LARGEFILE_CONFIGURE_ENABLE=	largefile

MYSQL_CONFIGURE_ON=	--with-mysql
MYSQL_CONFIGURE_OFF=	--with-mysql=no
MYSQL_USE=		MYSQL=yes

PGSQL_CONFIGURE_ON=	--with-pgsql
PGSQL_CONFIGURE_OFF=	--with-pgsql=no
PGSQL_USE=		PGSQL=yes

post-configure:
	@${REINPLACE_CMD} -e 's/^program_transform_name/#/' \
		${WRKSRC}/Makefile ${WRKSRC}/sysbench/Makefile

.include <bsd.port.mk>
