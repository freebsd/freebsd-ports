# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	qt
PORTVERSION=	4.8.5
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	RPM of QT4 (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-f10-${PORTNAME}45-[0-9]* linux-c6-${PORTNAME}47-[0-9]*

RPMVERSION=	12.el7_2
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	fontconfig png dbuslibs sqlite3 hicontheme openssl
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../../devel/${PORTNAME}4/pkg-descr

.include <bsd.port.mk>
