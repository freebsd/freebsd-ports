# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	uniconvw
PORTVERSION=	1.1.5
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	GOOGLE_CODE \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Gtk+ frontend for UniConvertor

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/sk1libs/__init__.py:graphics/sk1libs \
		${PYTHON_SITELIBDIR}/uniconvertor/__init__.py:graphics/uniconvertor \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:x11-toolkits/py-gtk2

PROJECTHOST=	uniconvertor

USES=		desktop-file-utils python
USE_PYTHON=	distutils
NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
