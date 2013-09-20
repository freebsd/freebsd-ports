# Created by: gahr
# $FreeBSD$

PORTNAME=	build
PORTVERSION=	0.3.9
CATEGORIES=	devel
MASTER_SITES=	http://www.codesynthesis.com/download/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A massively-parallel build system implemented on top of GNU make

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_GMAKE=	yes

MAKEFILE=	makefile
NO_BUILD=	yes
MAKE_ARGS=	install_prefix=${PREFIX}

PLIST_SUB=	BUILD_VER=${PORTVERSION:R}

NO_STAGE=	yes
.include <bsd.port.mk>
