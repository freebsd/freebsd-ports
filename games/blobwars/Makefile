# Created by: Loren M. Lang <lorenl@alzatex.com>
# $FreeBSD$

PORTNAME=	blobwars
PORTVERSION=	2.00
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Mission and Objective based 2D Platform Game

LICENSE=	GPLv2+ CC-BY-3.0 CC-BY-SA-3.0
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/doc/license

USES=		gmake pkgconfig
USE_SDL=	image2 mixer2 net2 sdl2 ttf2
WITH_ZLIB=	yes

INSTALLS_ICONS=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
			${WRKSRC}/Makefile
	${CHMOD} 664 ${WRKSRC}/icons/*

post-patch-DOCS-off:
	@${REINPLACE_CMD} \
		-e 's|mkdir -p $$(DESTDIR)$$(DOCDIR)|| ; \
		s|cp -p $$(DOCS) $$(DESTDIR)$$(DOCDIR)||' \
			${WRKSRC}/Makefile

post-patch-NLS-off:
	@${REINPLACE_CMD} -i '' -e '/LOCALE_MO =/d' \
		${WRKSRC}/Makefile

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
