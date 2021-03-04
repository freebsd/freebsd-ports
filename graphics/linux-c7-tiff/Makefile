# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	libtiff
PORTVERSION=	4.0.3
DISTVERSIONSUFFIX=	-35.el7
PORTREVISION=	5
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library routines for working with TIFF images (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	jbigkit jpeg
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*
DESCR=		${.CURDIR}/../tiff/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
