# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	tcl
PORTVERSION=	8.5.13
CATEGORIES=	lang linux
PKGNAMESUFFIX=	85

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Tool Command Language (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-${PORTNAME}${PKGNAMESUFFIX}-[0-9]* linux-c6-${PORTNAME}${PKGNAMESUFFIX}-[0-9]*

RPMVERSION=	8.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
USE_LINUX_RPM_BAD_PERMS=	yes

DATADIR=	${PREFIX}/usr/share/tcl${PORTVERSION:R}
DESCR=		${.CURDIR}/../${PORTNAME}${PKGNAMESUFFIX}/pkg-descr

.include <bsd.port.mk>
