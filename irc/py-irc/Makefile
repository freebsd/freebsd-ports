PORTNAME=	irc
PORTVERSION=	20.3.1
CATEGORIES=	irc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	IRC protocol client library for Python
WWW=		https://github.com/jaraco/irc

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jaraco.collections>0:devel/py-jaraco.collections@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.functools>=1.20:devel/py-jaraco.functools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.logging>0:devel/py-jaraco.logging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.stream>0:devel/py-jaraco.stream@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.text>3.10:devel/py-jaraco.text@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>0:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tempora>=1.6:devel/py-tempora@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	autoplist pep517 pytest

SHEBANG_FILES=	irc/*.py scripts/*.py

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
NO_ARCH=	yes

PORTEXAMPLES=	dccreceive.py dccsend.py irccat.py irccat2.py servermap.py \
		ssl-cat.py testbot.py

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	${CHMOD} -R o-w ${WRKSRC}/irc.egg-info

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${PORTEXAMPLES:S,^,${WRKSRC}/scripts/,} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
