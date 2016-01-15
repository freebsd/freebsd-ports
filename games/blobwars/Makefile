# Created by: Loren M. Lang <lorenl@alzatex.com>
# $FreeBSD$

PORTNAME=	blobwars
PORTVERSION=	2.00
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Mission and Objective based 2D Platform Game

LICENSE=	GPLv2+ CCbyNCSA3
LICENSE_COMB=	dual
LICENSE_NAME_CCbyNCSA3=Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_FILE=	${WRKSRC}/doc/license
LICENSE_TEXT_CCbyNCSA3=CC-BY 3.0
LICENSE_PERMS_CCbyNCSA3=dist-mirror pkg-mirror auto-accept

USES=		gmake pkgconfig
USE_SDL=	image2 mixer2 net2 sdl2 ttf2
WITH_ZLIB=	yes

INSTALLS_ICONS=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
			${WRKSRC}/Makefile

# Correct Permissions
	${CHMOD} 664 ${WRKSRC}/icons/*

.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} \
	-e 's|mkdir -p $$(DESTDIR)$$(DOCDIR)|| ; \
	s|cp -p $$(DOCS) $$(DESTDIR)$$(DOCDIR)||' \
		${WRKSRC}/Makefile
.endif

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -i '' -e '/LOCALE_MO =/d' \
		${WRKSRC}/Makefile
.endif

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/48x48/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
