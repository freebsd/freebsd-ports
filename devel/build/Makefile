# Created by: gahr
# $FreeBSD$

PORTNAME=	build
PORTVERSION=	0.3.10
CATEGORIES=	devel
MASTER_SITES=	http://www.codesynthesis.com/download/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Massively-parallel build system implemented on top of GNU make

LICENSE=	GPLv2

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake tar:bzip2

NO_BUILD=	yes
MAKEFILE=	makefile
MAKE_ARGS=	install_prefix=${STAGEDIR}${PREFIX}

PLIST_SUB=	BUILD_VER=${PORTVERSION:R}

.include <bsd.port.mk>
