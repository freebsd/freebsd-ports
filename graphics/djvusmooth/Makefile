# $FreeBSD$

PORTNAME=	djvusmooth
DISTVERSION=	0.2.19-39
DISTVERSIONSUFFIX=	-g0723947
CATEGORIES=	graphics python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical editor for DjVu

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xsltproc:textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/xhtml/chunk.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml
RUN_DEPENDS=	djvulibre>0:graphics/djvulibre \
		${PYTHON_PKGNAMEPREFIX}python-djvulibre>0:graphics/py-djvulibre \
		${PYTHON_PKGNAMEPREFIX}wxPython30>0:x11-toolkits/py-wxPython30

USES=		desktop-file-utils gettext-tools python
USE_GITHUB=	yes
GH_ACCOUNT=	jwilk
USE_PYTHON=	distutils autoplist noflavors
NO_ARCH=	yes

.include <bsd.port.mk>
