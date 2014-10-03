# Created by: Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	sysbench
PORTVERSION=	0.4.12
PORTREVISION=	3
CATEGORIES=	benchmarks databases
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/
#		Project gone from sourceforge, both site and downloads
#		Something exists on launchpad (https://code.launchpad.net/sysbench)
#		maybe the port swould be switched there, however there are no
#		direct downloads

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular, cross-platform, and multi-threaded benchmark tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool
GNU_CONFIGURE=	yes

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

.include <bsd.port.mk>
