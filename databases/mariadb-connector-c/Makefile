PORTNAME=	mariadb-connector-c
PORTVERSION=	3.2.6
CATEGORIES=	databases
MASTER_SITES=	https://mirror.nodesdirect.com/${SITESDIR}/ \
		https://mirror.one.com/${SITESDIR}/ \
		https://ftp.nluug.nl/db/${SITESDIR}/ \
		https://ftp.icm.edu.pl/pub/unix/database/${SITESDIR}/ \
		https://mirror.truenetwork.ru/${SITESDIR}/ \
		https://mirrors.aliyun.com/${SITESDIR}/ \
		https://ftp.ubuntu-tw.org/mirror/${SITESDIR}/ \
		https://mirror.kku.ac.th/${SITESDIR}/ \
		https://espejito.fder.edu.uy/${SITESDIR}/ \
		https://mirror1.cl.netactuate.com/${SITESDIR}/ \
		https://ftp.osuosl.org/pub/${SITESDIR}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	MariaDB database connector for C

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libcurl.so:ftp/curl

CONFLICTS_INSTALL=	mariadb[0-9]*-client \
			mariadb102-server \
			mysql[0-9]*-client \
			percona[0-9]*-client

USES=		cmake:insource compiler:c++11-lib iconv:translit ssl
USE_LDCONFIG=	${PREFIX}/lib/mariadb
SITESDIR=	mariadb/connector-c-${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/mysql

CMAKE_ARGS+=	-DCOMPILATION_COMMENT="FreeBSD Ports" \
		-DWITH_EXTERNAL_ZLIB="YES"

.include <bsd.port.mk>
