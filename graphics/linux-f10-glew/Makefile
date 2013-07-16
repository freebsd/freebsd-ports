# $FreeBSD$

PORTNAME=	glew
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	graphics linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	OpenGL Extension Wrangler Library (Linux Fedora 10)

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_NAME=	glew
LINUX_DIST_VER=	10
RPMVERSION=	1.fc10
USE_LDCONFIG=	yes
BRANDELF_DIRS=	usr/bin

PLIST_FILES=	usr/bin/glewinfo usr/bin/visualinfo \
		usr/lib/libGLEW.so.1.5 usr/lib/libGLEW.so.1.5.1
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	LICENSE.txt

.include <bsd.port.mk>
