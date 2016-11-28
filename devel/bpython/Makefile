# Created by: Yi-Jheng Lin <yzlin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bpython
PORTVERSION=	0.16
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://bpython-interpreter.org/releases/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Fancy interface to the Python interpreter

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=0:textproc/py-sphinx
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}curtsies>=0.1.18:devel/py-curtsies \
		${PYTHON_PKGNAMEPREFIX}greenlet>=0:devel/py-greenlet \
		${PYTHON_PKGNAMEPREFIX}pygments>=0:textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>=1.5:devel/py-six

OPTIONS_DEFINE=	EXAMPLES NLS
OPTIONS_SUB=	yes

NO_ARCH=	yes
USE_PYTHON=	autoplist distutils
USES=		python

PORTEXAMPLES=	light.theme sample.theme

NLS_USES=		gettext

post-patch:
	@${REINPLACE_CMD} -e '/build\/man\/bpython/d; /data\/bpython.desktop/d' ${WRKSRC}/setup.py

post-install:
	${INSTALL_MAN} ${WRKSRC}/build/man/bpython.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/build/man/bpython-config.5 ${STAGEDIR}${PREFIX}/man/man5/
	${INSTALL_DATA} ${WRKSRC}/data/bpython.desktop ${STAGEDIR}${DESKTOPDIR}/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}/

post-install-NLS-on:
.for lang in it_IT nl_NL
	${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/
.endfor
.for lang in de es_ES it_IT nl_NL
	${INSTALL_DATA} ${WRKSRC}/bpython/translations/${lang}/LC_MESSAGES/bpython.mo ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/
.endfor

.include <bsd.port.mk>
