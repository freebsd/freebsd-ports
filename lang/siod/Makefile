# New ports collection makefile for:   siod
# Version required:    3.4
# Date created:        28 April 1999
# Whom:                jkoshy
#
# $FreeBSD$
#

DISTNAME=	siod
PKGNAME=	siod-3.4
CATEGORIES=	lang
MASTER_SITES=	http://people.delphi.com/gjc/\
		ftp://ftp.std.com/pub/gjc/ \
		http://freefall.freebsd.org/~jkoshy/PORTS/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jkoshy@FreeBSD.org

NO_WRKSUBDIR=	true
MAKEFILE=	makefile
ALL_TARGET=	freebsd
MAKE_ENV=	LD_LIBRARY_PATH=.

MAN1=	siod.1 snapshot-dir.1 snapshot-compare.1 http-get.1 \
	cp-build.1 ftp-cp.1 csiod.1 ftp-put.1 ftp-test.1 ftp-get.1 \
	http-stress.1 proxy-server.1

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
