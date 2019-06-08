# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	7.29.0
DISTVERSIONSUFFIX=	-51.el7
PORTREVISION=	5
CATEGORIES=	ftp linux
LIB_DISTNAMES=	lib${DISTNAME}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Tool for transferring files with URL syntax (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	MIT

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	libssh2 nspr nss openldap
USE_LINUX_RPM=	nolib

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
