PORTNAME=	shed-skin
DISTVERSION=	0.9.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
DISTNAME=	${PORTNAME:S/-/_/g}-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Restricted Python-to-C++ compiler
WWW=		https://shedskin.github.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	boehm-gc>0:devel/boehm-gc \
		pcre>0:devel/pcre

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

post-extract:
	@${RM} ${WRKSRC}/tests/test_ops_assignment/test_ops_assignment.py.orig

post-patch:
	# the fouth regex below is a workaround for https://github.com/shedskin/shedskin/issues/470
	@${REINPLACE_CMD} -e ' \
		s|^CC=.*|CC=${CXX}|; \
		s|^CCFLAGS=|CCFLAGS?=-I${PREFIX}/include |; \
		s|^LFLAGS=|LFLAGS=-L${PREFIX}/lib |; \
		s|^CCFLAGS.*|& -I$$(SHEDSKIN_LIBDIR)|; \
		' ${WRKSRC}/shedskin/resources/flags/FLAGS

.include	<bsd.port.mk>
