# Created by: Loren M. Lang <lorenl@alzatex.com>
# $FreeBSD$

PORTNAME=	blobwars
PORTVERSION=	1.19
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mission and Objective based 2D Platform Game

LICENSE=	GPLv2 CCbyNCSA3 # GPLv2 or later
LICENSE_COMB=	dual
LICENSE_NAME_CCbyNCSA3=Attribution-NonCommercial-ShareAlike 3.0 Unported
LICENSE_FILE=	${WRKSRC}/doc/license
LICENSE_TEXT_CCbyNCSA3=CC-BY 3.0
LICENSE_PERMS_CCbyNCSA3=dist-mirror pkg-mirror auto-accept

USES=		gmake
USE_SDL=	image mixer net sdl ttf
WITH_ZLIB=	yes
MAKEFILE=	makefile

INSTALLS_ICONS=	yes

PORTDOCS=	*.gif *.png *.html changes hacking porting readme samples

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} \
		-e 's|mkdir -p $$(DESTDIR)$$(DOCDIR)|| ; \
		s|cp -p $$(DOCS) $$(DESTDIR)$$(DOCDIR)|| ; \
		s|USEPAK ?= 0|USEPAK ?= 1| ; \
		s|/usr|${LOCALBASE}| ; \
		s|$$(PREFIX)/games/|$$(PREFIX)/bin/| ; \
		s|/share/games/blobwars/|/share/blobwars/| ; \
		s| -Werror||' \
		-e '/LIBS =/s/-lz/-lz -lintl/' \
			${WRKSRC}/makefile

.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -i '' -e '/LOCALE_MO =/d' \
		${WRKSRC}/makefile
.endif

post-install:
	${LN} -sf ${PREFIX}/share/icons/hicolor/64x64/apps/${PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
