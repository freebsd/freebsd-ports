# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tiled
PORTVERSION=	0.15.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics editors games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	General purpose tile map editor

LICENSE=	GPLv2 # or later
LICENSE+=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	bjorn

USES=		compiler:c++11-lib desktop-file-utils qmake shared-mime-info
USE_QT5=	core gui widgets opengl buildtools_build linguisttools_build
USE_GL=		gl
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	PYTHON DOCS
OPTIONS_DEFAULT=PYTHON
OPTIONS_SUB=	yes

PYTHON_DESC=	Enable python plugin
PYTHON_USES=	pkgconfig python:2.7
PYTHON_QMAKE_OFF=	DISABLE_PYTHON_PLUGIN=yes

post-patch:
	@${FIND} ${WRKSRC} -name "*.pro" -exec ${REINPLACE_CMD} -e 's|share/man|man|' {} \;

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
