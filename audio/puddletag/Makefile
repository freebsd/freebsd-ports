# $FreeBSD$

PORTNAME=	puddletag
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=v
CATEGORIES=	audio python

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Audio tag editor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	chromaprint>=0.4:audio/chromaprint \
		${PYTHON_PKGNAMEPREFIX}musicbrainz2>=0:audio/py-musicbrainz2 \
		${PYTHON_PKGNAMEPREFIX}mutagen>=1.14:audio/py-mutagen \
		${PYTHON_PKGNAMEPREFIX}configobj>=4.5.0:devel/py-configobj \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=1.5.1:devel/py-pyparsing

USE_GITHUB=	yes
GH_ACCOUNT=	keithgg

USES=		python:2 pyqt:4
USE_PYTHON=	autoplist distutils
USE_PYQT=	gui_run svg_run
WRKSRC_SUBDIR=	source
NO_BUILD=	yes
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} 's|share/man/man1|man/man1|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
