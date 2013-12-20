# Created by: Junji NAKANISHI <jun-g@daemonfreaks.com>
# $FreeBSD$

PORTNAME=	mecab
PORTVERSION=	0.996
CATEGORIES=	japanese python textproc
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	Python bindings for MeCab

LICENSE=	BSD GPLv2 LGPL21
LICENSE_COMB=	dual

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	mecab:${PORTSDIR}/japanese/mecab

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_EGGINFO=	${PORTNAME}_python-${PKGVERSION}-${PYTHON_VERSION:S/thon//}.egg-info

NO_STAGE=	yes
pre-patch:
	@${REINPLACE_CMD} -e 's|cmd1("mecab-config --version")|"${PKGVERSION}"|' \
		${WRKSRC}/setup.py

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${PYTHON_PKGNAMEPREFIX}

.include <bsd.port.post.mk>
