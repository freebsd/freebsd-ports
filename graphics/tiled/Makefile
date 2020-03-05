# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tiled
PORTVERSION=	1.3.3
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics editors games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	General purpose tile map editor

LICENSE=	BSD2CLAUSE BSD3CLAUSE GPLv2+
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	bjorn

USES=		compiler:c++14-lang desktop-file-utils gl qmake qt:5 \
		shared-mime-info xorg
USE_QT=		core gui widgets opengl network declarative \
		buildtools_build linguisttools_build
USE_GL=		gl
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	PYTHON DOCS
OPTIONS_DEFAULT=PYTHON
OPTIONS_SUB=	yes

PYTHON_DESC=	Enable python plugin
PYTHON_USES=	pkgconfig python:3.6+
PYTHON_QMAKE_OFF=	DISABLE_PYTHON_PLUGIN=yes

post-patch:
	@${FIND} ${WRKSRC} -name "*.pro" -exec ${REINPLACE_CMD} -e 's|share/man|man|' {} \;

post-patch-PYTHON-on:
	@${REINPLACE_CMD} -e 's|python3|python-${PYTHON_VER}|' \
		${WRKSRC}/src/plugins/python/find_python.pri

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS README.md NEWS.md
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
