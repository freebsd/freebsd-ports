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

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	GIMP plugin to sharpen by increasing contrast in high frequency space

LICENSE=	EZPERSPECTIVE
LICENSE_NAME=	End User License Agreement
LICENSE_FILE=	${FILESDIR}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept
LICENSE_DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gimp-2.0.pc:${PORTSDIR}/graphics/gimp-app \
		${LOCALBASE}/libexec/gimp/2.2/python/gimpfu.py:${PORTSDIR}/graphics/py-gimp

USES=		zip
USE_PYTHON_RUN=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_SUB=	PLUGIN_DIR=${PLUGIN_DIR}
PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins/

# installed files
PLIST_FILES=	%%PLUGIN_DIR%%/${DISTNAME}

# installed dirs
PLIST_DIRSTRY=	libexec/gimp/2.2/plug-ins \
		libexec/gimp/2.2 \
		libexec/gimp

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
