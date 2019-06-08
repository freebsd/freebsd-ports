# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	libasyncns
PORTVERSION=	0.8
DISTVERSIONSUFFIX=	-7.el7
PORTREVISION=	1
CATEGORIES=	dns devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library for executing DNS queries (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	LGPL21+

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
