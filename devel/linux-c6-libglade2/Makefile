# Created by: lme
# $FreeBSD$

PORTNAME=	libglade2
PORTVERSION=	2.6.4
PORTREVISION=	1
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of libglade2 (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-libglade2-[0-9]* linux-f10-libglade2-[0-9]*

USE_LINUX=	c6
USE_LINUX_RPM=	yes

RPMVERSION=	3.1.el6
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libglade-2.0.so.0 usr/lib/libglade-2.0.so.0.0.7 \
		usr/share/xml/libglade/glade-2.0.dtd
PLIST_DIRS=	usr/share/xml/libglade usr/share/xml \
		usr/lib/libglade/2.0 usr/lib/libglade
DOCSDIR=	usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING NEWS README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
