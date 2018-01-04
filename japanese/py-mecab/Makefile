# Created by: Junji NAKANISHI <jun-g@daemonfreaks.com>
# $FreeBSD$

PORTNAME=	mecab
PORTVERSION=	0.996
PORTREVISION=	2
CATEGORIES=	japanese python textproc
MASTER_SITES=	https://drive.google.com/uc?export=download&id=0B4y35FiV1wh7UlJpaWJKM01KRVE&dummy=/
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	Python bindings for MeCab

LICENSE=	BSD3CLAUSE GPLv2 LGPL21
LICENSE_COMB=	dual

BUILD_DEPENDS=	swig3.0:devel/swig30
LIB_DEPENDS=	libmecab.so:japanese/mecab

USES=		python:2.7
USE_PYTHON=	distutils
PYDISTUTILS_EGGINFO=	${PORTNAME}_python-${PORTVERSION}.post2-py${PYTHON_VER}.egg-info

pre-patch:
	@${REINPLACE_CMD} -e 's|cmd1("mecab-config --version")|"${PKGVERSION}"|' \
		${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_MeCab.so

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${PYTHON_PKGNAMEPREFIX}

.include <bsd.port.post.mk>
