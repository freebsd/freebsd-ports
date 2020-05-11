# Created by: Yi-Jheng Lin <yzlin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bpython
PORTVERSION=	0.19
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		https://bpython-interpreter.org/releases/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fancy interface to the Python interpreter

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SPHINX}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}curtsies>=0.1.18:devel/py-curtsies@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenlet>=0:devel/py-greenlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.5:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/*.theme ${STAGEDIR}${EXAMPLESDIR}/

post-install-NLS-on:
.for lang in es_ES fr_FR it_IT nl_NL
	${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/
.endfor
.for lang in de es_ES fr_FR it_IT nl_NL
	${INSTALL_DATA} ${WRKSRC}/bpython/translations/${lang}/LC_MESSAGES/bpython.mo ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/
.endfor

.include <bsd.port.mk>
