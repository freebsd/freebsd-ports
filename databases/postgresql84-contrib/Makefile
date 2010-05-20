# New ports collection makefile for:	postgresql-contrib
# Date created:		June 10, 2003
# Whom:			Palle Girgensohn <girgen@pingpong.net>
#
# $FreeBSD$
#

PORTNAME=	postgresql
PKGNAMESUFFIX=	-contrib
CATEGORIES=	databases

MAINTAINER=	girgen@FreeBSD.org
COMMENT=	The contrib utilities from the PostgreSQL distribution

USE_PGSQL=	yes
DEFAULT_PGSQL_VER=84
MASTERDIR=	${.CURDIR}/../postgresql${DEFAULT_PGSQL_VER}-server

USE_BISON=	build

BUILD_DIRS=	src/port contrib
INSTALL_DIRS=	contrib

SLAVE_ONLY=	yes
CONFIGURE_ARGS+=--with-libxslt --with-libxml
LIB_DEPENDS=	xslt.2:${PORTSDIR}/textproc/libxslt xml2.5:${PORTSDIR}/textproc/libxml2

post-install:
	@- ${INSTALL_DATA} ${WRKSRC}/contrib/README ${DOCSDIR}/contrib/README

.include "${MASTERDIR}/Makefile"
