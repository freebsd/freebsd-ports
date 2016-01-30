# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	sqlite
PORTVERSION=	3.6.20
PORTREVISION=	3
CATEGORIES=	databases linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library that implements an embeddable SQL database engine (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f8-sqlite3-[0-9]* linux-f10-sqlite3-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
RPMVERSION=	1.el6_7.2
USE_LINUX_RPM=	yes
BRANDELF_FILES=	usr/bin/sqlite3
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/sqlite-${PORTVERSION}
PORTDOCS=	README
DESCR=		${.CURDIR}/../${PORTNAME}3/pkg-descr

.include <bsd.port.mk>
