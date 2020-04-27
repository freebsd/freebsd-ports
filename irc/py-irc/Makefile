# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	irc
PORTVERSION=	13.1
PORTREVISION=	2
CATEGORIES=	irc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	IRC protocol client library for Python

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hgtools>0:devel/py-hgtools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes
SHEBANG_FILES=	irc/*.py scripts/*.py

PORTEXAMPLES=	irccat.py irccat2.py servermap.py testbot.py \
		dccreceive.py dccsend.py ssl-cat.py
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	${CHMOD} -R o-w ${WRKSRC}/irc.egg-info

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${PORTEXAMPLES:S,^,${WRKSRC}/scripts/,} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}jaraco.util13>0:devel/py-jaraco.util13@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}jaraco.util>0:devel/py-jaraco.util@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
