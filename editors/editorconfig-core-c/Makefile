# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	editorconfig-core-c
PORTVERSION=	0.11.5
CATEGORIES=	editors

MAINTAINER=	knu@FreeBSD.org
COMMENT=	EditorConfig core library and executable written in C

USE_GITHUB=	yes
GH_ACCOUNT=	editorconfig
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	c5e2a58

USES=		cmake
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		SHLIB_MAJOR=${PORTVERSION:C/\..+//} \
		SHLIB_VER=${PORTVERSION}

.include <bsd.port.mk>
