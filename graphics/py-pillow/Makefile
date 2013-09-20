# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pillow
PORTVERSION=	2.0.0
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYDISTUTILS_PKGNAME}-${PORTVERSION}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Fork of the Python Imaging Library (PIL)

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		freetype:${PORTSDIR}/print/freetype2

USE_GITHUB=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

GH_ACCOUNT=	python-imaging
GH_PROJECT=	${PYDISTUTILS_PKGNAME}
GH_COMMIT=	baea361

CONFLICTS_INSTALL=	py*-imaging-*

PYDISTUTILS_PKGNAME=	Pillow
PYEASYINSTALL_ARCHDEP=	yes

regression-test: extract
	@cd ${WRKSRC} && \
	${PYTHON_CMD} ${PYSETUP} build_ext -i && \
	${PYTHON_CMD} selftest.py

NO_STAGE=	yes
.include <bsd.port.mk>
