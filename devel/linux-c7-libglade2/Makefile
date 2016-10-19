# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	libglade2
PORTVERSION=	2.6.4
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of libglade2 (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/usr/share/doc/${PORTNAME}-${PORTVERSION}/COPYING

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

RPMVERSION=	11.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

PORTDOCS=	AUTHORS COPYING NEWS README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
