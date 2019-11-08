# $FreeBSD$

PORTNAME=		mat
DISTVERSION=		0.6.1-12
DISTVERSIONSUFFIX=	-g4b9a657
CATEGORIES=		deskutils

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Metadata Anonymization Toolkit

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>0:devel/py-python-distutils-extra@${PY_FLAVOR} \
		intltool-update:textproc/intltool
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mutagen>=0:audio/py-mutagen@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdfrw>=0:textproc/py-pdfrw@${PY_FLAVOR} \
		srm:security/srm

USES=		gettext gnome python:2.7
USE_GITLAB=	yes
GL_SITE=	https://0xacab.org
GL_ACCOUNT=	mat
GL_COMMIT=	4b9a65758da4bb27724ac1f94162810a29cb3877
USE_PYTHON=	distutils autoplist
USE_GNOME=	gtk30 pygobject3
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		IMAGE
OPTIONS_DEFAULT=	IMAGE

IMAGE_DESC=		Image file support

IMAGE_RUN_DEPENDS=	exiftool:graphics/p5-Image-ExifTool

.include <bsd.port.mk>
