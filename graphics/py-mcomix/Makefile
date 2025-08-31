PORTNAME=	mcomix
DISTVERSION=	2.2.1
PORTREVISION=	4
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

NO_ARCH=	yes
USES=		desktop-file-utils gnome python
USE_GNOME=	gtk30 pygobject3

USE_PYTHON=	autoplist distutils

OPTIONS_DEFINE=	RAR
OPTIONS_DEFAULT=RAR

RAR_DESC=	RAR (.cbr) comic book archives support
RAR_RUN_DEPENDS=${LOCALBASE}/lib/libunrar.so:archivers/libunrar

.include <bsd.port.mk>
