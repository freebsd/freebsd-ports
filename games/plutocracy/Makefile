# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plutocracy
PORTVERSION=	0.0.20081229
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Multiplayer 3D economy/trade-based RTS

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		python tar:bzip2
USE_SDL=	sdl pango
USE_GL=		gl glu
USE_PYTHON=	distutils
PYDISTUTILS_PKGVERSION=	0.0

WRKSRC=		${WRKDIR}/${PORTNAME}

SUB_FILES=	plutocracy_

PORTDOCS=	AUTHORS README
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|span font|span font_desc|' \
		${WRKSRC}/src/render/r_assets.c
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/plutocracy/api.so
	${INSTALL_SCRIPT} ${WRKSRC}/pluto.py ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/plutocracy_ ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
