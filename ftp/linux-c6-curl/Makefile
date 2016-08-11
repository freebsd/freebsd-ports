# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	7.19.7
PORTREVISION=	6
CATEGORIES=	ftp linux
DISTFILES=	curl-${PORTVERSION}-${RPMVERSION}.${LINUX_RPM_ARCH}.rpm
LIB_DISTFILES=	libcurl-${PORTVERSION}-${RPMVERSION}.${LINUX_RPM_ARCH}.rpm
MASTER_SITES=	CENTOS_LINUX

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Command line tool for transferring files with URL syntax (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-curl-[0-9]* linux-f10-curl-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64

USE_LINUX=	c6
USE_LINUX_APPS=	openldap libssh2 # cyrus-sasl2
USE_LINUX_RPM=	nolib
RPMVERSION=	52.el6
BRANDELF_FILES=	usr/bin/curl
USE_LDCONFIG=	yes

DOCSDIR=	usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	BUGS COPYING FEATURES README TODO CHANGES FAQ MANUAL RESOURCES TheArtOfHttpScripting
DESCR=	${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
