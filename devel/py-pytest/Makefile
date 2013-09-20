# $FreeBSD$

PORTNAME=	pytest
PORTVERSION=	2.3.5
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Cross-project testing tool for Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylib>=1.4.13:${PORTSDIR}/devel/py-pylib

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

PLIST_SUB+=	PYTHON_VER=${PYTHON_VER}

TEST_DEPENDS:=	${RUN_DEPENDS}

regression-test: build
	@cd ${WRKSRC} && PYTHONPATH=${WRKSRC} ${PYTHON_CMD} pytest.py --ignore=doc/ja

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-install:
.if ${PYTHON_REL} >= 320
.include "${PORTSDIR}/devel/py-virtualenv/files/py3k-fix-pkg-plist.inc"
.endif

.include <bsd.port.post.mk>
