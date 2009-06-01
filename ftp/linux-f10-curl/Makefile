# New ports collection makefile for:	ftp/linux-f10-curl
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	curl
PORTVERSION=	7.19.4
CATEGORIES=	ftp linux
PKGNAMEPREFIX=	linux-f10-
DISTFILES=	curl-7.19.4-4.fc10.i386.rpm \
		libcurl-7.19.4-4.fc10.i386.rpm

.if defined(PACKAGE_BUILDING)
SRC_DISTFILES=	curl-7.19.4-4.fc10.src.rpm
ALWAYS_KEEP_DISTFILES=	YES
.endif

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	The command line tool for transferring files with URL syntax (Linux Fedora 10)

CONFLICTS=	linux-curl-[0-9]* linux-f8-curl-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
USE_LDCONFIG=	yes
BRANDELF_FILES=	usr/bin/curl
DESCR=	${.CURDIR}/../${PORTNAME}/pkg-descr

PLIST_FILES=	usr/bin/curl usr/lib/libcurl.so.4 usr/lib/libcurl.so.4.1.1
DOCSDIR=	usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	BUGS COPYING FEATURES README TODO CHANGES FAQ MANUAL RESOURCES TheArtOfHttpScripting
MANPREFIX=	${PREFIX}/usr/share
MAN1=		curl.1

.include <bsd.port.mk>
