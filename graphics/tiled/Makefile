# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tiled
PORTVERSION=	1.1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics editors games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	General purpose tile map editor

LICENSE=	BSD2CLAUSE BSD3CLAUSE GPLv2+
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	bjorn

USES=		compiler:c++11-lib desktop-file-utils qmake shared-mime-info
USE_QT5=	core gui widgets opengl network \
		buildtools_build linguisttools_build
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
.for f in AUTHORS README.md NEWS.md
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
