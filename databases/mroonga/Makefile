# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mroonga
PORTVERSION=	9.00
CATEGORIES=	databases textproc
MASTER_SITES=	http://packages.groonga.org/source/mroonga/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Open-source fulltext search engine for MySQL

LICENSE=	LGPL21

BUILD_DEPENDS=	${NONEXISTENT}:${_MYSQL_SERVER}:patch
LIB_DEPENDS=	libgroonga.so:textproc/groonga

USES=		libtool mysql pkgconfig

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-mysql-source="$$(cd ${PORTSDIR}/${_MYSQL_SERVER}; ${MAKE} -V WRKSRC)" \
		--with-mysql-build="$$(cd ${PORTSDIR}/${_MYSQL_SERVER}; ${MAKE} -V BUILD_WRKSRC)" \
		--with-mysql-config=${PREFIX}/bin/mysql_config

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mysql/plugin/ha_mroonga.so.0.0.0

.include <bsd.port.mk>
