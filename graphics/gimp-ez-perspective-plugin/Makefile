# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ez-perspective
PORTVERSION=	0.1.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://registry.gimp.org/files/
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-plugin
DISTNAME=	${PORTNAME}.py

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GIMP plugin to sharpen by increasing contrast in high frequency space

LICENSE=	EZPERSPECTIVE
LICENSE_NAME=	End User License Agreement
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept
LICENSE_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gimp-2.0.pc:graphics/gimp-app \
		${LOCALBASE}/libexec/gimp/2.2/python/gimpfu.py:graphics/py-gimp

USES=		python:run zip
NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins

# installed files
PLIST_FILES=	${PLUGIN_DIR}/${DISTNAME}

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/python|${PYTHON_CMD}|' \
		${WRKSRC}/${DISTNAME}

do-install:
# plugin
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PLUGIN_DIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
		${STAGEDIR}${PREFIX}/${PLUGIN_DIR}

.include <bsd.port.mk>
