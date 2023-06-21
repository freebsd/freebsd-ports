PORTNAME=	mcomix
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/MComix-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	shoesoft@gmx.net
COMMENT=	GTK3 comic book viewer
WWW=		https://sourceforge.net/projects/mcomix/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=5.2.0:graphics/py-pillow@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		desktop-file-utils gnome python:3.8+
USE_GNOME=	gtk30 pygobject3

USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	RAR
OPTIONS_DEFAULT=RAR

RAR_DESC=	RAR (.cbr) comic book archives support
RAR_RUN_DEPENDS=${LOCALBASE}/lib/libunrar.so:archivers/libunrar

.include <bsd.port.mk>
