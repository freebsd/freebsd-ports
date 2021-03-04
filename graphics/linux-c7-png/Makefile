# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	libpng
PORTVERSION=	1.5.13
DISTVERSIONSUFFIX=	-8.el7
PORTREVISION=	3
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library for manipulating PNG images (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	LIBPNG
LICENSE_NAME=	libpng license
LICENSE_FILE=	${WRKSRC}/usr/share/doc/${PORTNAME}-${PORTVERSION}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*
DESCR=		${.CURDIR}/../png/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
