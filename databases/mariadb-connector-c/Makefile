# $FreeBSD$

PORTNAME=	mariadb
PORTVERSION=	2.3.1
CATEGORIES=	databases ipv6
MASTER_SITES=	http://ftp.osuosl.org/pub/${SITESDIR}/ \
		http://mirrors.supportex.net/${SITESDIR}/ \
		http://mirror2.hs-esslingen.de/pub/Mirrors/${SITESDIR}/ \
		http://gd.tuwien.ac.at/db/${SITESDIR}/ \
		http://mirrors.fe.up.pt/pub/${SITESDIR}/ \
		http://mirror.de.gsnw.de:56431/${SITESDIR}/ \
		http://mirror.layerjet.com/${SITESDIR}/ \
		http://mirror.switch.ch/mirror/${SITESDIR}/
PKGNAMESUFFIX=	connector-c
DISTNAME=	${PORTNAME}-${PKGNAMESUFFIX}-${PORTVERSION}-src

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	MariaDB database connector for C

LICENSE=	LGPL21

CONFLICTS_INSTALL=	mariadb[0-9]*-client-* \
			mariadb102-server-* \
			mysql[0-9]*-client-* \
			percona[0-9]*-client-*

USES=		cmake compiler:c++11-lib ssl
USE_LDCONFIG=	${PREFIX}/lib/mysql
SITESDIR=	mariadb/connector-c-${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/mysql

CMAKE_ARGS+=	-DCOMPILATION_COMMENT="FreeBSD Ports" \
		-DWITH_EXTERNAL_ZLIB="YES"

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/include/mariadb/CMakeFiles
.	for f in CMakeLists.txt Makefile Makefile.am cmake_install.cmake
		${RM} ${STAGEDIR}${PREFIX}/include/mariadb/${f}
.	endfor

.include <bsd.port.mk>
