# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	nspr
PORTVERSION=	4.21.0
DISTVERSIONSUFFIX=	-1.el7
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Netscape Portable Runtime (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
