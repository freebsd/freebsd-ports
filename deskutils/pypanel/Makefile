# Created by: Florian Unglaub <flo@btw23.de>
# $FreeBSD$

PORTNAME=	pypanel
PORTVERSION=	2.4
PORTREVISION=	12
CATEGORIES=	deskutils
MASTER_SITES=	SF
DISTNAME=	PyPanel-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop panel written in Python

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libImlib2.so:graphics/imlib2
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Xlib/X.py:x11-toolkits/py-xlib@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2.7
USE_PYTHON=	autoplist distutils
USE_XORG=	xft

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/bin/freetype-config|${LOCALBASE}/bin/freetype-config|; \
		 s|/usr/bin/imlib2-config|${LOCALBASE}/bin/imlib2-config|; \
		 s|/usr/X11R6/include|${LOCALBASE}/include|; \
		 s|"COPYING", "README", ||' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e \
		's|sysconfig\.get_python_lib()|"${PREFIX}/share"|' \
			${WRKSRC}/setup.py ${WRKSRC}/pypanel
	@${REINPLACE_CMD} -e \
		's|/usr/lib/libImlib2.so.1|${LOCALBASE}/lib/libImlib2.so|' \
		${WRKSRC}/setup.py ${WRKSRC}/ppmodule.c
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' ${WRKSRC}/pypanel
	@${REINPLACE_CMD} -e 's|/usr/share/imlib2|${LOCALBASE}/share/imlib2|' \
		${WRKSRC}/pypanelrc

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/ppmodule.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
