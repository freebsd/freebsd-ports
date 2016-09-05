# Created by: bsam
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	7.19.6
PORTREVISION=	1
CATEGORIES=	ftp linux
LIB_DISTFILES=	lib${DISTNAME}${EXTRACT_SUFX}
SRC_DISTFILES=	${DISTNAME}${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Command line tool for transferring files with URL syntax (Linux Fedora 10)

CONFLICTS=	linux-curl-[0-9]* linux-f8-curl-[0-9]*

USES=		linux:f10
USE_LINUX=	cyrus-sasl2 openldap
USE_LINUX_RPM=	nolib

RPMVERSION=	2.fc10
USE_LDCONFIG=	yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

PLIST_FILES=	usr/bin/curl usr/lib/libcurl.so.4 usr/lib/libcurl.so.4.1.1 \
		usr/share/man/man1/curl.1.gz
PORTDOCS=	BUGS COPYING FEATURES README TODO CHANGES FAQ MANUAL RESOURCES TheArtOfHttpScripting

.include <bsd.port.mk>
