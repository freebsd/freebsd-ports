# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	7.29.0
PORTREVISION=	2
CATEGORIES=	ftp linux
LIB_DISTNAMES=	lib${DISTNAME}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Tool for transferring files with URL syntax (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	MIT

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
RPMVERSION=	35.el7.centos
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	libssh2 nspr nss openldap
USE_LINUX_RPM=	nolib

.include <bsd.port.mk>
