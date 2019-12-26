# Created by: Gustavo Fukao <gustavofukao@gmail.com>
# $FreeBSD$

PORTNAME=	gazpacho
PORTVERSION=	0.7.2
PORTREVISION=	7
CATEGORIES=	devel python
MASTER_SITES=	GNOME/sources/gazpacho/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI builder for the GTK+ toolkit

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	LGPL21+ # source mentions LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}kiwi-gtk>=0:x11-toolkits/py-kiwi-gtk@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		desktop-file-utils gettext gnome python:2.7
USE_GNOME=	pygtk2
USE_PYTHON=	distutils
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	AUTHORS ChangeLog CONTRIBUTORS README NEWS

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|share/doc/gazpacho/examples|${EXAMPLESDIR}|g' ${WRKSRC}/setup.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/gazpacho.desktop ${STAGEDIR}${PREFIX}/share/applications/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
