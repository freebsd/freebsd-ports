# Created by: gahr
# $FreeBSD$

PORTNAME=	build
PORTVERSION=	0.3.10
CATEGORIES=	devel
MASTER_SITES=	https://www.codesynthesis.com/download/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Massively-parallel build system implemented on top of GNU make

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		gmake tar:bzip2
MAKEFILE=	makefile
MAKE_ARGS=	install_prefix=${STAGEDIR}${PREFIX}

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_SUB=	BUILD_VER=${PORTVERSION:R}

.include <bsd.port.mk>
