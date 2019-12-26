# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	gnofract4d
DISTVERSIONPREFIX=	V_
DISTVERSION=	3_14_1
PORTREVISION=	5
CATEGORIES=	graphics gnome

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Weird GNOME fractal generator

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	docbook-xsl>0:textproc/docbook-xsl
LIB_DEPENDS=	libpng.so:graphics/png
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USE_GITHUB=	yes
GH_ACCOUNT=	edyoung

USES=		desktop-file-utils display:build gnome jpeg localbase pathfix \
		pkgconfig python:2.7 shared-mime-info shebangfix
SHEBANG_FILES=	fractutils/get.py
USE_GNOME=	intlhack libxslt:build pygtk2
USE_PYTHON=	distutils autoplist

PLIST_FILES=	man/man1/gnofract4d.1.gz

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD}  -e 's|/usr/include/|${LOCALBASE}/include/|; \
		/# doc files/,+2d; /"html"/,+1d' \
		${WRKSRC}/setup.py
	@${REINPLACE_CMD}  -e 's|"CC"|"${CC}"|; s|"gcc"|"${CC}"|' \
		${WRKSRC}/setup.py \
		${WRKSRC}/fract4d/test_fractconfig.py \
		${WRKSRC}/fract4d/fc.py
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' \
		${WRKSRC}/fract4d/test_codegen.py \
		${WRKSRC}/fract4d/fractconfig.py

post-build:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} createdocs.py)

post-install:
.for l in fract4d_stdlib fract4dc
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/fract4d/${l}.so
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
