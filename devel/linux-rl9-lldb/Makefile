PORTNAME=	lldb
PORTVERSION=	19.1.7
DISTVERSIONSUFFIX=	-1.el9
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	The LLVM Debugger for LLVM suite (Rocky Linux ${LINUX_DIST_VER})
WWW=		http://llvm.org

LICENSE=	GPLv2+

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	elfutils-libelf python3
USE_LINUX_RPM=	yes
WANT_LINUX32=yes

BIN_DISTNAMES=	${PORTNAME}-${DISTVERSIONFULL}
LIB_DISTNAMES=	${PORTNAME}-devel-${DISTVERSIONFULL}
# src rpm is missing
SRC_DISTFILES=

DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

.include <bsd.port.mk>
