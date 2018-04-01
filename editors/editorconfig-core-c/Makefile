# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	editorconfig-core-c
PORTVERSION=	0.12.2
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	knu@FreeBSD.org
COMMENT=	EditorConfig core library and executable written in C

BROKEN=		fails to package

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	editorconfig

USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		SHLIB_MAJOR=${PORTVERSION:C/\..+//} \
		SHLIB_VER=${PORTVERSION}

.include <bsd.port.mk>
