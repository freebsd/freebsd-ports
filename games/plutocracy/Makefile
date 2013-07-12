# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	plutocracy
PORTVERSION=	0.0.20081229
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Multiplayer 3D economy/trade-based RTS

LICENSE=	GPLv2

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_SDL=	sdl pango
USE_GL=		gl glu
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
INSTALLS_EGGINFO=	yes
PYDISTUTILS_PKGVERSION=	0.0

WRKSRC=		${WRKDIR}/${PORTNAME}

SUB_FILES=	plutocracy_

PORTDOCS=	AUTHORS README

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|span font|span font_desc|' \
		${WRKSRC}/src/render/r_assets.c
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/setup.py

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pluto.py ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/plutocracy_ ${PREFIX}/bin/${PORTNAME}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
