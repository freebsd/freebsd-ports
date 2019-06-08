# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	qt47
PORTVERSION=	4.7.2
DISTVERSIONSUFFIX=	-1_18.el6
PORTREVISION=	4
CATEGORIES=	devel linux
MASTER_SITES=	LOCAL/tijl/atrpms:amd64,i386
SRC_DISTFILES=	# unavailable
DIST_SUBDIR=	atrpms

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Cross-platform application and UI framework (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	fontconfig png dbuslibs sqlite3 openssl
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
