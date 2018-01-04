# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	uniconvw
PORTVERSION=	1.1.5
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	https://downloads.sk1project.net/uniconvertor/v1.1.5/ \
		https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/uniconvertor/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Gtk+ frontend for UniConvertor

LICENSE=	LGPL20+ GPLv2+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/src/GNU_GPL_v2
LICENSE_FILE_LGPL20+ =	${WRKSRC}/src/GNU_LGPL_v2

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/sk1libs/__init__.py:graphics/sk1libs \
		${PYTHON_SITELIBDIR}/uniconvertor/__init__.py:graphics/uniconvertor \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:x11-toolkits/py-gtk2@${FLAVOR}

USES=		desktop-file-utils python:2.7
USE_PYTHON=	distutils
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
