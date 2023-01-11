PORTNAME=	p4python
PORTVERSION=	2016.1.1447008
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Python bindings for the Perforce API
WWW=		https://www.perforce.com/perforce/r14.2/manuals/p4script/python.programming.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_riscv64=		fails to build: TypeError: can only concatenate str (not "NoneType") to str

BUILD_DEPENDS+=	${LOCALBASE}/lib/perforce/libclient.a:devel/p4api
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		dos2unix python:3.6+ ssl
USE_PYTHON=	distutils autoplist
PYDISTUTILS_BUILDARGS=	--ssl ${OPENSSLLIB}

post-patch:
	@${REINPLACE_CMD} -e 's:%%LOCALBASE%%:${LOCALBASE}:' ${WRKSRC}/setup.py

.include <bsd.port.mk>
