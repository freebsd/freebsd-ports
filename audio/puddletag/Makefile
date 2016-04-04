# $FreeBSD$

PORTNAME=	puddletag
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Audio tag editor

LICENSE=	GPLv3

RUN_DEPENDS=	chromaprint>=0.4:audio/chromaprint \
		${PYTHON_PKGNAMEPREFIX}musicbrainz2>=0:audio/py-musicbrainz2 \
		${PYTHON_PKGNAMEPREFIX}mutagen>=1.14:audio/py-mutagen \
		${PYTHON_PKGNAMEPREFIX}configobj>=4.5.0:devel/py-configobj \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=1.5.1:devel/py-pyparsing \
		${PYTHON_PKGNAMEPREFIX}qt4-svg>=4.5.0:graphics/py-qt4-svg \
		${PYTHON_PKGNAMEPREFIX}qt4-gui>=4.5.0:x11-toolkits/py-qt4-gui

USES=		python:2
USE_PYTHON=	autoplist distutils
INSTALLS_ICONS=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} 's|share/man/man1|man/man1|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
