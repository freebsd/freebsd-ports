# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	starfighter
PORTVERSION=	1.5.1.1
CATEGORIES=	games
MASTER_SITES=	SAVANNAH/${PORTNAME}/1.5 \
		SF/nemysisfreebsdp/${CATEGORIES}/${PORTNAME}/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}-src${EXTRACT_SUFX} \
		${PORTNAME}-icons${EXTRACT_SUFX}:icons
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Liberate the universe from the evil company WEAPCO

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}-src

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake dos2unix iconv pkgconfig
USE_SDL=	image2 mixer2

DOS2UNIX_GLOB=	*.txt

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	README.txt

DOCSRCDIR2=	${WRKSRC}/docs/
DOCSDIR2=	${DOCSDIR}/docs/
DOC_FILES2=	*.png *.html

OPTIONS_DEFINE= DOCS

INSTALLS_ICONS= yes
ICON_SIZES=     16x16 32x32 48x48 64x64 72x72 96x96 128x128

post-patch:
	@${REINPLACE_CMD} \
	-e 's| -O2 -Wall|${CXXFLAGS}| ; \
	s|mkdir -p $$(DESTDIR)$$(DOCDIR)|| ; \
	s|cp $$(DOCS) $$(DESTDIR)$$(DOCDIR)|| ; \
	s|/usr|${LOCALBASE}| ; \
	s|$$(PREFIX)/games/|$$(PREFIX)/bin/| ; \
	s|/share/games/parallelrealities/|/share/starfighter/|' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.for s in ${ICON_SIZES}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${s}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${s}/apps/${PORTNAME}.png
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
