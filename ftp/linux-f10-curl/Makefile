# Created by: bsam
# $FreeBSD: head/ftp/linux-f10-curl/Makefile 362311 2014-07-20 11:55:55Z rene $

PORTNAME=	curl
PORTVERSION=	7.19.6
PORTREVISION=	1
CATEGORIES=	ftp linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTFILES=	curl-${PORTVERSION}-${RPMVERSION}.i386.rpm \
		libcurl-${PORTVERSION}-${RPMVERSION}.i386.rpm

.if defined(PACKAGE_BUILDING)
SRC_DISTFILES=	curl-${PORTVERSION}-${RPMVERSION}.src.rpm
ALWAYS_KEEP_DISTFILES=	YES
.endif

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Command line tool for transferring files with URL syntax (Linux Fedora 10)

FORBIDDEN=	http://www.freshports.org/vuxml.php?vid=9aecb94c-c1ad-11e3-a5ac-001b21614864

CONFLICTS=	linux-curl-[0-9]* linux-f8-curl-[0-9]*

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	cyrus-sasl2 openldap
LINUX_DIST_VER=	10
RPMVERSION=	2.fc10
USE_LDCONFIG=	yes
BRANDELF_FILES=	usr/bin/curl
DESCR=	${.CURDIR}/../${PORTNAME}/pkg-descr

PLIST_FILES=	usr/bin/curl usr/lib/libcurl.so.4 usr/lib/libcurl.so.4.1.1 \
		usr/share/man/man1/curl.1.gz
DOCSDIR=	usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	BUGS COPYING FEATURES README TODO CHANGES FAQ MANUAL RESOURCES TheArtOfHttpScripting

.include <bsd.port.mk>
