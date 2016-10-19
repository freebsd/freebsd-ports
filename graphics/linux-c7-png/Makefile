# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	png
PORTVERSION=	1.5.13
CATEGORIES=	graphics linux
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of the PNG lib (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	LIBPNG
LICENSE_NAME=	libpng license
LICENSE_FILE=	${WRKSRC}/usr/share/doc/lib${PORTNAME}-${PORTVERSION}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CONFLICTS=	linux-f10-${PORTNAME}-[0-9]* linux-c6-${PORTNAME}-[0-9]*

LINUX_NAME=	libpng
RPMVERSION=	5.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	CHANGES LICENSE README TODO example.c libpng-manual.txt
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
