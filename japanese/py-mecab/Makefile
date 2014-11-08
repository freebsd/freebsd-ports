# Created by: Junji NAKANISHI <jun-g@daemonfreaks.com>
# $FreeBSD$

PORTNAME=	mecab
PORTVERSION=	0.996
PORTREVISION=	1
CATEGORIES=	japanese python textproc
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	Python bindings for MeCab

LICENSE=	BSD3CLAUSE GPLv2 LGPL21
LICENSE_COMB=	dual

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	libmecab.so:${PORTSDIR}/japanese/mecab

USES=		python
USE_PYTHON=	distutils
PYDISTUTILS_EGGINFO=	${PORTNAME}_python-${PKGVERSION}-${PYTHON_VERSION:S/thon//}.egg-info

pre-patch:
	@${REINPLACE_CMD} -e 's|cmd1("mecab-config --version")|"${PKGVERSION}"|' \
		${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_MeCab.so

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${PYTHON_PKGNAMEPREFIX}

.include <bsd.port.post.mk>
