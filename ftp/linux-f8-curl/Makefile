# New ports collection makefile for:	ftp/linux-f8-curl
# Date created:				2009-03-30
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	curl
PORTVERSION=	7.18.2
PORTREVISION=	2
CATEGORIES=	ftp linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	The command line tool for transferring files with URL syntax (Linux Fedora 8)

CONFLICTS=	linux-curl-[0-9]* linux-f10-curl-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	8
RPMVERSION=	7.fc8
USE_LDCONFIG=	yes
BRANDELF_FILES=	usr/bin/curl
DESCR=	${.CURDIR}/../${PORTNAME}/pkg-descr

PLIST_FILES=	usr/bin/curl usr/lib/libcurl.so.4 usr/lib/libcurl.so.4.1.0
DOCSDIR=	usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	BUGS COPYING FEATURES README TODO CHANGES FAQ MANUAL RESOURCES TheArtOfHttpScripting
MANPREFIX=	${PREFIX}/usr/share
MAN1=		curl.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
