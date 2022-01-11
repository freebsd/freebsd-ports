# Created by: Yi-Jheng Lin <yzlin@FreeBSD.org>

PORTNAME=	bpython
PORTVERSION=	0.22.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		https://bpython-interpreter.org/releases/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fancy interface to the Python interpreter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.1.3,1:textproc/py-sphinx@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}curtsies>=0.3.5:devel/py-curtsies@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cwcwidth>=0:devel/py-cwcwidth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenlet>=0:devel/py-greenlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>=0:devel/py-xdg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=0:devel/py-typing-extensions@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.cached-property>=0:devel/py-backports.cached-property@${PY_FLAVOR}
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
