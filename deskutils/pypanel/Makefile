# New ports collection makefile for:	pypanel
# Date created:				24 October 2005
# Whom:					Florian Unglaub
#
# $FreeBSD$
#

PORTNAME=	pypanel
PORTVERSION=	2.4
PORTREVISION=	6
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	pypanel
DISTNAME=	PyPanel-${PORTVERSION}

MAINTAINER=	u0@rootofallevil.net
COMMENT=	Desktop panel written in Python

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		Xft.2:${PORTSDIR}/x11-fonts/libXft
BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/Xlib/X.py:${PORTSDIR}/x11-toolkits/py-xlib
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/Xlib/X.py:${PORTSDIR}/x11-toolkits/py-xlib

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_EFL=	imlib2
PYDISTUTILS_PKGNAME=	PyPanel

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/bin/freetype-config|${LOCALBASE}/bin/freetype-config|; \
		 s|/usr/bin/imlib2-config|${LOCALBASE}/bin/imlib2-config|; \
		 s|/usr/X11R6/include|${LOCALBASE}/include|; \
		 s|"COPYING", "README", ||' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|sysconfig\.get_python_lib()|"${PREFIX}/share"|' \
		${WRKSRC}/setup.py ${WRKSRC}/pypanel
	@${REINPLACE_CMD} -e \
		's|/usr/lib/libImlib2.so.1|${LOCALBASE}/lib/libImlib2.so|' \
		${WRKSRC}/setup.py ${WRKSRC}/ppmodule.c
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|' ${WRKSRC}/pypanel
	@${REINPLACE_CMD} -e 's|/usr/share/imlib2|${LOCALBASE}/share/imlib2|' \
		${WRKSRC}/pypanelrc

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
