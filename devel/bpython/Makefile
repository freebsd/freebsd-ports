PORTNAME=	bpython
PORTVERSION=	0.26
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://bpython-interpreter.org/releases/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fancy interface to the Python interpreter
WWW=		https://bpython-interpreter.org/ \
		https://docs.bpython-interpreter.org/en/latest/ \
		https://github.com/bpython/bpython

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=62.4.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=1.1.3,1:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}curtsies>=0.4.0:devel/py-curtsies@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cwcwidth>=0:devel/py-cwcwidth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenlet>=0:devel/py-greenlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>=0:devel/py-xdg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31100
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}
.endif

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/theme/*.theme ${STAGEDIR}${EXAMPLESDIR}/

post-install-NLS-on:
.for lang in es_ES fr_FR it_IT nl_NL
	${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/
.endfor
.for lang in de es_ES fr_FR it_IT nl_NL
	${INSTALL_DATA} ${WRKSRC}/bpython/translations/${lang}/LC_MESSAGES/bpython.mo ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/
.endfor

.include <bsd.port.post.mk>
