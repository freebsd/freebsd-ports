# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pycogent
PORTVERSION=	1.5.3
PORTREVISION=	2
CATEGORIES=	biology python
MASTER_SITES=	SF/${PORTNAME}/PyCogent/${PORTVERSION}
DISTNAME=	PyCogent-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A toolkit for statistical analysis of biological sequences

BUILD_DEPENDS=	${PYNUMPY} \
		${LOCALBASE}/bin/cython:${PORTSDIR}/lang/cython \
		${LOCALBASE}/bin/sphinx-build:${PORTSDIR}/textproc/py-sphinx \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy06>=0.5:${PORTSDIR}/databases/py-sqlalchemy06
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	cogent

NO_STAGE=	yes
.include <bsd.port.mk>
