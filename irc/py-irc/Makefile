PORTNAME=	irc
PORTVERSION=	20.1.0
CATEGORIES=	irc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	IRC protocol client library for Python

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jaraco.functools>=1.20:devel/py-jaraco.functools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.logging>0:devel/py-jaraco.logging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.util>0:devel/py-jaraco.util@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>0:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tempora>=1.6:devel/py-tempora@${PY_FLAVOR}

USES=		python:3.7+ shebangfix
USE_PYTHON=	autoplist distutils pytest

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
