PORTNAME=	mariadb
PORTVERSION=	3.1.11
CATEGORIES=	databases
MASTER_SITES=	http://ftp.osuosl.org/pub/${SITESDIR}/ \
		http://mirrors.supportex.net/${SITESDIR}/ \
		http://mirror2.hs-esslingen.de/pub/Mirrors/${SITESDIR}/ \
		http://gd.tuwien.ac.at/db/${SITESDIR}/ \
		http://mirrors.fe.up.pt/pub/${SITESDIR}/ \
		http://mirror.de.gsnw.de:56431/${SITESDIR}/ \
		http://mirror.layerjet.com/${SITESDIR}/ \
		http://mirror.switch.ch/mirror/${SITESDIR}/
PKGNAMESUFFIX=	-connector-odbc
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSION}-ga-src

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	MariaDB database connector for odbc

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libodbc.so:databases/unixODBC \
		libmariadb.so:databases/mariadb-connector-c

USES=		cmake:insource ssl
USE_LDCONFIG=	${PREFIX}/lib/mariadbconnector-odbc

SITESDIR=	${PORTNAME}/${PKGNAMESUFFIX:S/^-//}-${PORTVERSION:S/.b$//}
DOCSDIR=	${PREFIX}/share/doc/mysql

OPTIONS_DEFINE=	SSL
OPTIONS_DEFAULT=SSL

CMAKE_ARGS+=	-DCOMPILATION_COMMENT="FreeBSD Ports"
CFLAGS+=	-I${LOCALBASE}/include/mariadb
LDFLAGS+=	-L${LOCALBASE}/lib/mariadb

SSL_CMAKE_ON=	-DWITH_OPENSSL=on

PLIST_FILES=	lib/mariadb/libmaodbc.so

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX} \
		${STAGEDIR}${PREFIX}/docs

.include <bsd.port.mk>
