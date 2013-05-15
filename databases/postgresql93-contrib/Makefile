# Created by: Palle Girgensohn <girgen@pingpong.net>
# $FreeBSD$

PORTNAME=	postgresql
PORTREVISION=	0
CATEGORIES=	databases
PKGNAMESUFFIX=	-contrib

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	The contrib utilities from the PostgreSQL distribution

LIB_DEPENDS=	xslt.2:${PORTSDIR}/textproc/libxslt \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_PGSQL=	yes
DEFAULT_PGSQL_VER=93
MASTERDIR=	${.CURDIR}/../postgresql${DEFAULT_PGSQL_VER}-server

USES=		bison

BUILD_DIRS=	src/port src/common contrib
INSTALL_DIRS=	contrib

SLAVE_ONLY=	yes
CONFIGURE_ARGS+=--with-libxslt --with-libxml --with-openssl --disable-nls
LDFLAGS+=	${PTHREAD_LIBS} -L${PREFIX}/lib

OPTIONS_DEFINE=	OSSP_UUID
OSSP_UUID_DESC=	Enable / disable ossp-uuid support
OPTIONS_DEFAULT=	OSSP_UUID

post-install:
	@- ${INSTALL_DATA} ${WRKSRC}/contrib/README ${DOCSDIR}/extension/README

.include "${MASTERDIR}/Makefile"
