PORTNAME=	mariadb-connector-c
PORTVERSION=	3.4.5
CATEGORIES=	databases
MASTER_SITES=	\
		https://ftp.nluug.nl/db/${SITESDIR}/ \
		https://mirror.nodesdirect.com/${SITESDIR}/ \
		https://mirror.one.com/${SITESDIR}/ \
		https://ftp.icm.edu.pl/pub/unix/database/${SITESDIR}/ \
		https://mirror.truenetwork.ru/${SITESDIR}/ \
		https://mirrors.aliyun.com/${SITESDIR}/ \
		https://ftp.ubuntu-tw.org/mirror/${SITESDIR}/ \
		https://mirror.kku.ac.th/${SITESDIR}/ \
		https://espejito.fder.edu.uy/${SITESDIR}/ \
		https://ftp.osuosl.org/pub/${SITESDIR}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	MariaDB database connector for C
WWW=		https://www.mariadb.com/kb/en/mariadb/about-mariadb-connector-c/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libzstd.so:archivers/zstd

CONFLICTS_INSTALL=	mariadb[0-9]*-client \
			mariadb102-server \
			mysql[0-9]*-client \
			percona[0-9]*-client

OPTIONS_SINGLE=		GSSAPI
OPTIONS_SINGLE_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT GSSAPI_NONE
OPTIONS_DEFAULT=	GSSAPI_BASE
OPTIONS_SUB=		yes

GSSAPI_BASE_USES=	gssapi
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_USES=	gssapi:mit
GSSAPI_NONE_CMAKE_ON=	-DPLUGIN_AUTH_GSSAPI_CLIENT=OFF

USES=		cmake:insource compiler:c++11-lib iconv:translit ssl
USE_LDCONFIG=	${PREFIX}/lib/mariadb
SITESDIR=	mariadb/connector-c-${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/mysql

CMAKE_ARGS+=	-DCOMPILATION_COMMENT="FreeBSD Ports" \
		-DWITH_EXTERNAL_ZLIB="YES" \
		-DINSTALL_MANDIR:PATH=${PREFIX}/share/man

.include <bsd.port.mk>
