# New ports collection makefile for:    py-mecab
# Date created:                         27 August 2007
# Whom:                                 Junji NAKANISHI <jun-g@daemonfreaks.com>
#
# $FreeBSD$

PORTNAME=	mecab
PORTVERSION=	0.97
CATEGORIES=	japanese python textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-python/${PORTVERSION}
DISTNAME=	${PORTNAME}-python-${PORTVERSION}

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	Python bindings for MeCab

BUILD_DEPENDS=	swig>=1.3:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	mecab.1:${PORTSDIR}/japanese/mecab

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_EGGINFO=	${PORTNAME}_python-${PKGVERSION}-${PYTHON_VERSION:S/thon//}.egg-info

pre-patch:
	@${REINPLACE_CMD} -e 's|cmd1("mecab-config --version")|"${PKGVERSION}"|' \
		${WRKSRC}/setup.py

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${PYTHON_PKGNAMEPREFIX}

.include <bsd.port.post.mk>
