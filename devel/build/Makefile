# New ports collection Makefile for:	build
# Date created:				14 June 2010
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	build
PORTVERSION=	0.3.7
CATEGORIES=	devel
MASTER_SITES=	http://www.codesynthesis.com/download/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A massively-parallel build system implemented on top of GNU make 

USE_BZIP2=	yes
USE_GMAKE=	yes

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKEFILE=	makefile
NO_BUILD=	yes
MAKE_ARGS=	install_prefix=${PREFIX}

PLIST_SUB=	BUILD_VER=${PORTVERSION:R}

.include <bsd.port.mk>
