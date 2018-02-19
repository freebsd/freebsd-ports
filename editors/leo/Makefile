# Created by: Alan Eldridge <ports@geeksrus.net>
# $FreeBSD$

PORTNAME=	leo
PORTVERSION=	5.3
PORTREVISION=	2
CATEGORIES=	editors python
MASTER_SITES=	SF/${PORTNAME}/Leo/${PORTVERSION}-final
DISTNAME=	Leo-${PORTVERSION}-final
DIST_SUBDIR=	leo

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced outline editor for programmers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${FLAVOR} \
		silvercity>0:textproc/silvercity

USES=		pyqt:4 python:2.7 shebangfix zip
SHEBANG_FILES=	leo/doc/html/fixup.pl leo/external/saveleo \
		leo/dist/leo-install.py leo/scripts/leo
USE_PYQT=	gui_run svg_run
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

DESKTOP_ENTRIES="Leo" "Literate Editor with Outlines" \
		"${PYTHONPREFIX_SITELIBDIR}/leo/Icons/leoapp32.png" "leo" "" ""

OPTIONS_DEFINE=		PYENCHANT

PYENCHANT_DESC=		Spell checking support via PyEnchant
PYENCHANT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}enchant>0:textproc/py-enchant@${FLAVOR}

post-patch:
	@${LN} -sf leo/dist/leo-install.py ${WRKSRC}/leo-install.py
	@${LN} -sf leo/dist/setup.py ${WRKSRC}/setup.py

post-install:
	@${REINPLACE_CMD} -e 's,===,==,' ${STAGEDIR}${PREFIX}/bin/leo \
		${STAGEDIR}${PREFIX}/bin/leoc

.include <bsd.port.mk>
