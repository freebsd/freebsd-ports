# Created by: Ting-Wei Lan <lantw44@gmail.com>
# $FreeBSD$

PORTNAME=	meson
PORTVERSION=	0.51.2
CATEGORIES=	devel python
MASTER_SITES=	https://github.com/mesonbuild/${PORTNAME}/releases/download/${PORTVERSION}/

PATCH_SITES=	https://github.com/mesonbuild/${PORTNAME}/commit/
PATCHFILES+=	efea48788ab2.patch:-p1

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	High performance build system

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	ninja:devel/ninja

USES=		python:3.5+
USE_PYTHON=	autoplist distutils noflavors
NO_ARCH=	yes

.include <bsd.port.mk>
