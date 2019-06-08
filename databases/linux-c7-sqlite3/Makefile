# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	sqlite
PORTVERSION=	3.7.17
DISTVERSIONSUFFIX=	-8.el7
PORTREVISION=	1
CATEGORIES=	databases linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library that implements an embeddable SQL database engine (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	PD

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}3/pkg-descr
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
