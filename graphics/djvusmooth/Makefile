# $FreeBSD$

PORTNAME=	djvusmooth
DISTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	graphics python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical editor for DjVu

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

BUILD_DEPENDS=	xsltproc:textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml
RUN_DEPENDS=	djvulibre>0:graphics/djvulibre \
		${PYTHON_PKGNAMEPREFIX}python-djvulibre>0:graphics/py-djvulibre@${PY_FLAVOR}

USES=		desktop-file-utils gettext-tools python:2.7
USE_WX=		3.0
WX_COMPS=	python:run
USE_GITHUB=	yes
GH_ACCOUNT=	jwilk
USE_PYTHON=	distutils autoplist noflavors
NO_ARCH=	yes

.include <bsd.port.mk>
