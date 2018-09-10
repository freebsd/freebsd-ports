# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	libglade2
PORTVERSION=	2.6.4
PORTREVISION=	1
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GNOME glade library (Linux CentOS ${LINUX_DIST_VER})

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/usr/share/doc/${PORTNAME}-${PORTVERSION}/COPYING

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
RPMVERSION=	11.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
