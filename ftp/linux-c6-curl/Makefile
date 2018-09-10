# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	7.19.7
PORTREVISION=	9
CATEGORIES=	ftp linux
LIB_DISTNAMES=	lib${DISTNAME}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Command line tool for transferring files with URL syntax (Linux CentOS ${LINUX_DIST_VER})

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
RPMVERSION=	53.el6_9
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	libssh2 nspr nss openldap
USE_LINUX_RPM=	nolib

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
