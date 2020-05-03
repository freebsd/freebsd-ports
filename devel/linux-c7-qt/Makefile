# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	qt
PORTVERSION=	4.8.7
DISTVERSIONSUFFIX=	-8.el7
PORTREVISION=	3
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of QT4 (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	fontconfig png dbuslibs sqlite3
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}47-[0-9]*
DATADIR=	${PREFIX}/usr/share/${PORTNAME}4

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
