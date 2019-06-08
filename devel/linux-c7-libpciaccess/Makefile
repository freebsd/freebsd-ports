# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	libpciaccess
PORTVERSION=	0.14
DISTVERSIONSUFFIX=	-1.el7
CATEGORIES=	devel

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Generic PCI access library (CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
