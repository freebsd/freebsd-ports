# Created by: Alan Eldridge <ports@geeksrus.net>
# $FreeBSD$

PORTNAME=	leo
PORTVERSION=	5.1
CATEGORIES=	editors python
MASTER_SITES=	SF/${PORTNAME}/Leo/${PORTVERSION}-final
DISTNAME=	Leo-${PORTVERSION}-final
DIST_SUBDIR=	leo

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced outline editor for programmers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}qt4-svg>0:${PORTSDIR}/graphics/py-qt4-svg \
		${PYTHON_PKGNAMEPREFIX}docutils>0:${PORTSDIR}/textproc/py-docutils \
		silvercity>0:${PORTSDIR}/textproc/silvercity \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>0:${PORTSDIR}/x11-toolkits/py-qt4-gui

NO_ARCH=	yes

USES=		python shebangfix zip
SHEBANG_FILES=	leo/doc/html/fixup.pl
USE_PYTHON=	autoplist distutils

DESKTOP_ENTRIES="Leo" "Literate Editor with Outlines" \
		"${PYTHONPREFIX_SITELIBDIR}/leo/Icons/leoapp32.png" "leo" "" ""

OPTIONS_DEFINE=		DOCS PYENCHANT

PYENCHANT_DESC=		Spell checking support via PyEnchant
PYENCHANT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}enchant>0:${PORTSDIR}/textproc/py-enchant

.include <bsd.port.mk>
