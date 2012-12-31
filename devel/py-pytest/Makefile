# $FreeBSD$

PORTNAME=	pytest
PORTVERSION=	2.3.4
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Cross-project testing tool for Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pylib>=1.4.12:${PORTSDIR}/devel/py-pylib

# Python 3 ready
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
USE_ZIP=		yes

PLIST_SUB+=	PYTHON_VER=${PYTHON_VER}

TEST_DEPENDS:=	${RUN_DEPENDS}

regression-test: build
	@cd ${WRKSRC} && PYTHONPATH=${WRKSRC} ${PYTHON_CMD} pytest.py --ignore=doc/ja

.include <bsd.port.pre.mk>

post-install:
.if ${PYTHON_REL} >= 320
.include "${PORTSDIR}/devel/py-virtualenv/files/py3k-fix-pkg-plist.inc"
.endif

.include <bsd.port.post.mk>
