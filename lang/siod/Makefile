# New ports collection makefile for:   siod
# Date created:        28 April 1999
# Whom:                jkoshy
#
# $FreeBSD$
#

PORTNAME=	siod
PORTVERSION=	3.4
CATEGORIES=	lang scheme
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR= jkoshy
DISTNAME=	siod
EXTRACT_SUFX=	.tgz

MAINTAINER=	jkoshy@FreeBSD.org
COMMENT=	A small footprint implementation of the Scheme programming language

INSTALLS_SHLIB=	yes

NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	freebsd
MAKE_ENV=	LD_LIBRARY_PATH=.

MAN1=	siod.1 snapshot-dir.1 snapshot-compare.1 http-get.1 \
	cp-build.1 ftp-cp.1 csiod.1 ftp-put.1 ftp-test.1 ftp-get.1 \
	http-stress.1 proxy-server.1

.include <bsd.port.mk>
