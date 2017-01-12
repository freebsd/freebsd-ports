# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	7.19.7
PORTREVISION=	9
CATEGORIES=	ftp linux
LIB_DISTFILES=	lib${DISTNAME}${EXTRACT_SUFX}
SRC_DISTFILES=	${DISTNAME}${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Command line tool for transferring files with URL syntax (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-curl-[0-9]* linux-f10-curl-[0-9]*

USES=		linux:c6
USE_LINUX=	libssh2 nspr nss openldap
USE_LINUX_RPM=	nolib
RPMVERSION=	52.el6
USE_LDCONFIG=	yes

PORTDOCS=	BUGS COPYING FEATURES README TODO CHANGES FAQ MANUAL RESOURCES TheArtOfHttpScripting
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
