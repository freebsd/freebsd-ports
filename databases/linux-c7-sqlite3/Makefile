# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	sqlite
PORTVERSION=	3.7.17
CATEGORIES=	databases linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library that implements an embeddable SQL database engine (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	PD

CONFLICTS=	linux-f10-${PORTNAME}3-[0-9]* linux-c6-${PORTNAME}-[0-9]*

RPMVERSION=	8.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

PORTDOCS=	README
DESCR=		${.CURDIR}/../${PORTNAME}3/pkg-descr

.include <bsd.port.mk>
