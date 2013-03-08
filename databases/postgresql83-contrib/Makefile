# Created by:	Palle Girgensohn <girgen@pingpong.net>
# $FreeBSD$

PORTNAME=	postgresql
PKGNAMESUFFIX=	-contrib
CATEGORIES=	databases

MAINTAINER=	pgsql@FreeBSD.org
COMMENT=	The contrib utilities from the PostgreSQL distribution

USE_PGSQL=	yes
DEFAULT_PGSQL_VER=83
MASTERDIR=	${.CURDIR}/../postgresql${DEFAULT_PGSQL_VER}-server

USES=		bison

BUILD_DIRS=	src/port contrib
INSTALL_DIRS=	contrib

SLAVE_ONLY=	yes
CONFIGURE_ARGS+=	--with-openssl

post-install:
	@- ${INSTALL_DATA} ${WRKSRC}/contrib/README ${DOCSDIR}/contrib/README

.include "${MASTERDIR}/Makefile"
