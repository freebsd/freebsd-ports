# $FreeBSD$

PORTNAME=	mailcap_fix
PORTVERSION=	0.1.3
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Mailcap module that correctly handles windcard entries

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/UNLICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	michael-lazar
GH_TAGNAME=	${PORTVERSION}
USES=		python:3.3+
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) && ${PYTHON_VER} != ${PYTHON_DEFAULT}
IGNORE=	you have python ${PYTHON_DEFAULT} set as the default, and this needs ${PYTHON_VER}
.endif

.include <bsd.port.post.mk>
