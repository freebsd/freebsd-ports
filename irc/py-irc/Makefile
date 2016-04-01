# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	irc
PORTVERSION=	13.1
CATEGORIES=	irc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	IRC protocol client library for Python

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hgtools>0:devel/py-hgtools \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>0:devel/py-pytest-runner \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}jaraco.util>0:devel/py-jaraco.util \
		${PYTHON_PKGNAMEPREFIX}setuptools_scm>0:devel/py-setuptools_scm

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

PORTEXAMPLES=	irccat.py irccat2.py servermap.py testbot.py \
		dccreceive.py dccsend.py ssl-cat.py
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	${CHMOD} -R o-w ${WRKSRC}/irc.egg-info

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${PORTEXAMPLES:S,^,${WRKSRC}/scripts/,} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
